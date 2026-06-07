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
    TreeNode* dfs(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        dfs(root);
        return root;
    }
};

// Method 2:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        root->left = right;
        root->right = left;
        return root;
    }
};
