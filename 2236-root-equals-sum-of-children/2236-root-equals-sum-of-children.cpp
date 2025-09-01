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
    void solve(TreeNode* root,bool &flag){
        if(!root || (!root->left && !root->right)) return;
        if(root->val != (root->right->val + root->left->val)){
            flag = false;
            return;
        }
        solve(root->left,flag);
        solve(root->right,flag);
        return;
    }
    bool checkTree(TreeNode* root) {
        bool flag = true;
        solve(root,flag);
        return flag;
    }
};