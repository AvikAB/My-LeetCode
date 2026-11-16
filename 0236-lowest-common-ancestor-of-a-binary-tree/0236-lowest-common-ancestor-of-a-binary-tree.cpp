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
        if(!root) return NULL;  // bc

        // a node is also can be ancestor thats why
        if(root->val==p->val or root->val==q->val) return root;

        TreeNode* lLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rLCA = lowestCommonAncestor(root->right, p, q);

        // now cases:
        if(lLCA and rLCA) return root;
        else if(lLCA!=NULL) return lLCA;
        else return rLCA;
    }
};



/* a node is also can be its ancestor.
Each & Every level, we will find left LCA & right LCA. if any node get both then it will be LCA.

1. lLCA==NULL or rLCA==NULL -> return Null to prev node.
2. lLCA==Null or rLCA!=Null -> then return the valid val which is rLCA.
3. lLCA!=Null or rLCA==Null -> also return the valid val (lLCA) to prev node.
4. !lLCA and !rLCA -> that node is LCA for p,q.
*/