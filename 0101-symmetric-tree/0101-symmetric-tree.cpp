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

    bool check(TreeNode* l, TreeNode* r){
        if(!l and !r) return true;    // both subtrees are null

        if((l==NULL and r!=NULL) or (r==NULL and l!=NULL)) return false;   // One of them is not null & other is null - false

        if((l->val==r->val) and check(l->left, r->right) and check(l->right, r->left)) return true;   // vals are equal & mirror check (draw the diagram)

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;  // empty tree
        return check(root->left, root->right);
    }
};