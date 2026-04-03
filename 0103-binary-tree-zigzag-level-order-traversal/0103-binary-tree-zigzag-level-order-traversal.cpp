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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // Start with Left to Right for level 0
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                // If leftToRight is true: place at index i (left to right)
                // If leftToRight is false: place at index size-1-i (right to left)
                int index = leftToRight ? i : (size-1-i);
                level[index] = curr->val;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            // after this level
            ans.push_back(level);
            leftToRight = !leftToRight;  // Toggle for next level
        }
        return ans;
    }
};