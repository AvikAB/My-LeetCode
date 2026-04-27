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
  public:
    int find(vector<int>inorder, int target, int start, int end){
        for(int i=start; i<=end; i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    
    TreeNode* Tree(vector<int> &inorder, vector<int> &postorder, int InSt, int InEnd, int idx){
        if(InSt>InEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = find(inorder, postorder[idx], InSt, InEnd);
        
        // Right:
        root->right = Tree(inorder, postorder, pos+1, InEnd, idx-1);
        // left:
        root->left = Tree(inorder, postorder, InSt, pos-1, idx-(InEnd-pos)-1);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n = inorder.size();
        return Tree(inorder, postorder, 0, n-1, n-1);
    }
};

// O(n^2)