/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,int> inorderMap;  // val -> index mapping
    
    TreeNode* Tree(vector<int>&preorder, int InSt, int InEnd, int &idx){
        if(InSt>InEnd) return NULL;
        
        TreeNode *root = new TreeNode(preorder[idx]);
        int pos = inorderMap[preorder[idx]];
        idx++;
        
        root->left = Tree(preorder, InSt, pos-1, idx);
        root->right = Tree(preorder, pos+1, InEnd, idx);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int>&preorder, vector<int>&inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return Tree(preorder, 0, inorder.size()-1, preorderIndex);
    }
};