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
    void function(TreeNode* root,int targetSum,int currSum,vector<vector<int>> &ans,vector<int> temp){
            if(!root) return;
            currSum += root->val;
            temp.push_back(root->val);
            if(!root->left && !root->right){
                if(targetSum == currSum){
                    ans.push_back(temp);
                }
            }
            function(root->left,targetSum,currSum,ans,temp);
            function(root->right,targetSum,currSum,ans,temp);
            return;
        }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        function(root,targetSum,0,ans,temp);
        return ans;

    }
};