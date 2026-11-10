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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        // search
        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        } else if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }

        // found the node
        // C1: leaf
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // C2: one child
        if(!root->right){   // only left child present
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        if(!root->left){    // only right child present
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // C3: two children — use inorder predecessor (max of left subtree)
        TreeNode* child = root->left;
        TreeNode* parent = root;

        while(child->right){  // go to the righmost child in left subt  
            parent = child;
            child = child->right;
        }

        if(root != parent){
            parent->right = child->left;
            child->left = root->left;
            child->right = root->right;
            delete root;
            return child;
        } else {
            child->right = root->right;
            delete root;
            return child;
        }
    }
};