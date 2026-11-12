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
    // optimized
    bool BST(TreeNode* root, long long &prev){
        if(!root) return true;

        bool l = BST(root->left, prev);
        if(l==false) return false;

        if(root->val <= prev) return false;
        else prev = root->val;

        return BST(root->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return BST(root, prev);
    }
};