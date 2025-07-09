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
    void function(TreeNode* root,int& ans,int currsum){
        if(!root) return;
        
        currsum = currsum * 10 + root->val;

        if(!root->left && !root->right){
            ans += currsum;
        }
        function(root->left,ans,currsum);
        function(root->right,ans,currsum);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int currsum = 0;
        function(root,ans,currsum);
        return ans;
    }
};