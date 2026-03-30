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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        // Base Cases:
        if(r1==NULL and r2==NULL) return true;  // if the nodes are leaf nodes or both are reached their end of tree
        if((!r1 and r2) or (r1 and !r2)) return false;  // if r1 present or r2 not or vice versa then its false
        if(r1->val!=r2->val) return false;   // if both nodes are not equal then its false

        return isSameTree(r1->left, r2->left) and isSameTree(r1->right, r2->right);  // check left subtree & right subtree
    }
};