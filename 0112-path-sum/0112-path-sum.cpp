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
    bool inOrder(TreeNode* root, int sum, int targetSum){
        if(!root) return false;
        
        sum += root->val;
        if(sum==targetSum and !root->left and !root->right) return true;

        bool left = inOrder(root->left, sum, targetSum);
        bool right = inOrder(root->right, sum, targetSum);
        return left or right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool res = inOrder(root, sum, targetSum);
        return res;
    }
};