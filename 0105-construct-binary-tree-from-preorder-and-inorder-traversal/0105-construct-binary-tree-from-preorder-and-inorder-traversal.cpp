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
int find(vector<int>&inorder, int target, int start, int end){
    for(int i=start; i<=end; i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}

TreeNode* Tree(vector<int>&inorder, vector<int>&preorder, int InSt, int InEnd, int idx){
    if(InSt>InEnd) return NULL;
    
    TreeNode *root = new TreeNode(preorder[idx]);  // new root create using preorder[idx] val
    int pos = find(inorder, preorder[idx], InSt, InEnd);
    
    // Build Left Part:
    root->left = Tree(inorder, preorder, InSt, pos-1, idx+1);
    // Build right part:
    root->right = Tree(inorder, preorder, pos+1, InEnd, idx+(pos-InSt)+1);
    return root;
}

class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        return Tree(inorder, preorder, 0, n-1, 0);  // (inorder, preorder, start_of_inorder, end_of_inorder, start_index_of_preorder)
    }
};

// O(n^2) Approach

// O(n) Approach using hashmap:
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
