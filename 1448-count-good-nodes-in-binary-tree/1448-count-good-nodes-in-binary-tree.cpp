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
    void function(TreeNode* root,int &count,int maxv){
        if(!root) return;
        if(root->val >= maxv){
            count++;
            maxv = root->val;
        }
        function(root->left,count,maxv);
        function(root->right,count,maxv);
        
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        int maxv = root->val;
        function(root,count,maxv);
        return count;
    }
};