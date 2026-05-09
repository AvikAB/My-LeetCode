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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode*, pair<int,int>>>q;  // this is for BFS (level order traversal)
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;  // node
            int vertical_line = p.second.first;  // col
            int level = p.second.second;  // row
            nodes[vertical_line][level].insert(curr->val);

            if(curr->left){
                q.push({curr->left, {vertical_line-1, level+1}});
            }
            if(curr->right){
                q.push({curr->right, {vertical_line+1, level+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto line_entry:nodes){
            vector<int>vertical_nodes;
            // for each level in this vertical line from top to bottom
            for(auto level_entry:line_entry.second){
                // add all vals at this (vertical_line, level) position
                vertical_nodes.insert(vertical_nodes.end(), level_entry.second.begin(), level_entry.second.end());
            }
            // add this vertical line to final ans
            ans.push_back(vertical_nodes);
        }
        return ans;
    }
};