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
    void postOrder(TreeNode* root, int &cnt){
        if(root==NULL) return;

        postOrder(root->left, cnt);     // visit left
        postOrder(root->right, cnt);   // visit right
        cnt++;     // visit node & cnt it
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        postOrder(root, cnt);
        return cnt;
    }
};