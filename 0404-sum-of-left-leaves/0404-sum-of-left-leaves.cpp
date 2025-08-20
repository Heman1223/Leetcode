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
    void solve(TreeNode* root,int &sum,bool flag){
        if(!root) return;
        solve(root->left,sum,true);
        if(!root->left && !root->right && flag){
            sum += root->val;
        }
        solve(root->right,sum,false);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum,false);
        return sum;
    }
};