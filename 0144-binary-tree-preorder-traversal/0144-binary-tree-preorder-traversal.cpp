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
    void preorder(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        // NLR
        ans.push_back(root->val);   // visit node
        preorder(root->left, ans);   // visit left
        preorder(root->right, ans);  // visit right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root, ans);
        return ans;
    }
};