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
    bool sameParent(TreeNode* root, int a, int b){
        if(!root) return false;
        if(root->left and root->right){
            // if any left or right is a or b then they are from same parent
            if(root->left->val==a and root->right->val==b) return true;
            if(root->left->val==b and root->right->val==a) return true;
        }
        return sameParent(root->left, a, b) or sameParent(root->right, a, b);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        // checking both are same level or not
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int l1 = -1, l2 = -1;
        while(!q.empty()){
            int lvlsz = q.size();
            for(int i=0; i<lvlsz; i++){
                TreeNode* curr = q.front();
                q.pop();
                // checking l1 & l2
                if(curr->val==x) l1 = level;
                if(curr->val==y) l2 = level;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            // both found at same level
            if(l1!=-1 and l2!=-1) break;

            // if one is found and other is not at this level, then they are not cousin
            if((l1!=-1 and l2==-1) or (l1==-1 and l2!=-1)) return false;
            level++;
        }

        // If both found at same level, check if they have different parent or not
        if(l1!=-1 and l2!=-1 and l1==l2){
            return !sameParent(root, x, y); // if a & b has same parent (return 1) then they're not cousin thats why '!'
        }
        return false;
    }
};