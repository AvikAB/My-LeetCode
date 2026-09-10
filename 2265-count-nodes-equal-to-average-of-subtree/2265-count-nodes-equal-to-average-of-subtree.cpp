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
    int ans;
    pair<int,int> solve(TreeNode* node){
        if(node==NULL) return {0,0};

        pair<int,int> left = solve(node->left);
        pair<int,int> right = solve(node->right);

        int sum = left.first + right.first + node->val;
        int cnt = left.second + right.second + 1;

        if(node->val == sum/cnt) ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};