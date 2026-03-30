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
    // Function to create a mirror of a tree
    TreeNode* mirror(TreeNode* root) {
        if(root == NULL) return NULL;
        
        TreeNode* mirrored = new TreeNode(root->val);
        mirrored->left = mirror(root->right);
        mirrored->right = mirror(root->left);
        
        return mirrored;
    }
    
    // Function to check if two trees are identical
    bool isIdentical(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        
        return (t1->val == t2->val) && 
               isIdentical(t1->left, t2->left) && 
               isIdentical(t1->right, t2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        // Create mirror of left subtree
        TreeNode* mirroredLeft = mirror(root->left);
        
        // Check if mirrored left is identical to right
        return isIdentical(mirroredLeft, root->right);
    }
};