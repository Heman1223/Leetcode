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
    vector<vector<int>> nodes;
    void dfs(TreeNode* root,int l,int im){
        if(!root) return;
        nodes.push_back({im,l,root->val});
        dfs(root->left,l + 1,im - 1);
        dfs(root->right,l + 1,im + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0 ,0); // lvl, im
        sort(nodes.begin(),nodes.end());
        map<int,vector<int>> mp;
        for(auto e : nodes){
            mp[e[0]].push_back(e[2]);
        }
        vector<vector<int>> ans;
        for(auto e : mp){
            ans.push_back(e.second);
        }
        return ans;
    }
};