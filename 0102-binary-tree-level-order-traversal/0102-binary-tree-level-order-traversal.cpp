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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int lvlSize = q.size();  // get the num of nodes at current level
            vector<int>currLevel;  // vector to store nodes at current level
            // Process all node at current level
            for(int i=0; i<lvlSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                // Add current node's data to current level
                currLevel.push_back(curr->val);

                // Add children for left node & right node
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            // add current level to answer
            ans.push_back(currLevel);
        }
        return ans;
    }
};