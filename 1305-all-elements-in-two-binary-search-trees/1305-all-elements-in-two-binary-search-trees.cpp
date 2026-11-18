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

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>s1, s2;
        // push node & all its left
        while(root1){
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2){
            s2.push(root2);
            root2 = root2->left;
        }

        while(!s1.empty() or !s2.empty()){
            // comparison
            int takefromS1;
            if(s1.empty()) takefromS1 = 0;
            else if(s2.empty()) takefromS1 = 1;
            else if(s1.top()->val > s2.top()->val) takefromS1 = 0;
            else takefromS1 = 1;

            // now, the work property of takefromS1
            if(takefromS1){
                TreeNode* curr = s1.top();
                s1.pop();
                ans.push_back(curr->val);  // add to the ans
                // now go to right side & take all left from that.
                // because of inorder traversal (LNR)
                curr = curr->right;
                while(curr){
                    s1.push(curr);
                    curr = curr->left;
                }
            } else {
                TreeNode* curr = s2.top();
                s2.pop();
                ans.push_back(curr->val);
                // now go to right side & take all left from that
                curr = curr->right;
                while(curr){
                    s2.push(curr);
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};