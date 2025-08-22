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
    void solve(TreeNode* root,int targetSum,int currSum,bool &ans){
        if(!root) return;
        currSum += root->val;
        if(!root->left && !root->right){
            if(targetSum == currSum){
                ans = true;
                return;
            }
        }
        solve(root->left,targetSum,currSum,ans);
        solve(root->right,targetSum,currSum,ans);
        return;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        solve(root,targetSum,0,ans);
        return ans;
    }
};