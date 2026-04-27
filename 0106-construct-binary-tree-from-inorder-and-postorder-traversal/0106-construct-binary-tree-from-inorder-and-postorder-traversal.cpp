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
    unordered_map<int,int> InorderMap;
    
    TreeNode* Tree(vector<int> &inorder, vector<int> &postorder, int InSt, int InEnd, int &idx){
        if(InSt>InEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = InorderMap[postorder[idx]];
        idx--;    // move backward for postorder
        
        // Right:
        root->right = Tree(inorder, postorder, pos+1, InEnd, idx);
        // left:
        root->left = Tree(inorder, postorder, InSt, pos-1, idx);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        for(int i=0; i<inorder.size(); i++){
            InorderMap[inorder[i]] = i;
        }

        int postOidx = postorder.size()-1;
        return Tree(inorder, postorder, 0, inorder.size()-1, postOidx);
    }
};

// O(n) Approach using hashmap