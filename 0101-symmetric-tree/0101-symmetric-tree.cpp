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
    bool function(TreeNode* Lroot,TreeNode* Rroot){
        if(!Lroot && !Rroot) return true;
        if(!Lroot || !Rroot) return false;
        if(Lroot->val != Rroot->val) return false;
        return function(Lroot->left,Rroot->right) && function(Lroot->right,Rroot->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return function(root->left,root->right);
    }
};