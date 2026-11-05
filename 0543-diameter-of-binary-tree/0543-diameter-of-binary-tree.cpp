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
    int solve(TreeNode* node, int &dia){
        if(!node) return 0;
        int l_dep = solve(node->left, dia);
        int r_dep = solve(node->right, dia);
        dia = max(dia, l_dep+r_dep);
        return 1+max(l_dep, r_dep);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root, dia);
        return dia;
    }
};