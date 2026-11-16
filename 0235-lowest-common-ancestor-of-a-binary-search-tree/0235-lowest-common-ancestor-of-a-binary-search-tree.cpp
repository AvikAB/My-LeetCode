/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val>p->val and root->val>q->val) // go to left
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val<p->val and root->val<q->val)  // go to right
            return lowestCommonAncestor(root->right, p, q);
        else return root;  // both are in both sides, this is LCA
    }
};