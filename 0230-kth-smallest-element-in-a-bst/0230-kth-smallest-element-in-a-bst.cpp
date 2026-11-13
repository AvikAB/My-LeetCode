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
    void inorder(TreeNode* node, int &k, int &ans){
        if(node==NULL or k<=0) return;  // bc
        // traverse left
        inorder(node->left, k, ans);
        // process the node
        k--;
        if(k==0){
            ans = node->val;
            return;
        }
        // traverse right
        inorder(node->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};