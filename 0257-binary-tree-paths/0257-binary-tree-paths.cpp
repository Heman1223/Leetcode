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
private:
    void findpath(TreeNode* node,vector<string>& ans,string temp){
        if(!node) return;
        temp = temp + to_string(node->val);
        //if(node -> left){
            findpath(node->left,ans,temp + "->");
       // }
        //if(node -> right){
            findpath(node->right,ans,temp + "->");
        //}
        if(!node->left && !node->right){
            ans.push_back(temp);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root){
            findpath(root,v,"");
        }
        return v;

    }
};