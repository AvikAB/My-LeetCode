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
    void Path(TreeNode* root, vector<string>&ans, string temp){
        temp += to_string(root->val);    // add curr node's val to the path

        if(root->left) Path(root->left, ans, temp+"->");     // traverse left
        if(root->right) Path(root->right, ans, temp+"->");   // traverse right
        if(!root->left and !root->right) ans.push_back(temp);  // leaf node found add whole path to it
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        Path(root, ans, "");
        return ans;
    }
};