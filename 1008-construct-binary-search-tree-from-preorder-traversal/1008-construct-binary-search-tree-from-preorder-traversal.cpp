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
    TreeNode* BST(vector<int>&preorder, int &idx, int lower, int upper){
        // base case
        if(idx==preorder.size() or preorder[idx]<lower or preorder[idx]>upper) return NULL;

        TreeNode* root = new TreeNode(preorder[idx++]); // new node
        root->left = BST(preorder, idx, lower, root->val);
        root->right = BST(preorder, idx, root->val, upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return BST(preorder, idx, INT_MIN, INT_MAX);
    }
};