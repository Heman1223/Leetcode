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
    void leafs(TreeNode* root,vector<int> &l){
        if(!root) return;
        if(!root->left && !root->right){
            l.push_back(root->val);
        }
        leafs(root->right,l);
        leafs(root->left,l);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1;
        vector<int> l2;
        leafs(root1,l1);
        leafs(root2,l2);
        if(l1.size() != l2.size()) return false;
        for(int i=0;i<l1.size();i++){
            if(l1[i] != l2[i]) return false;
        }
        return true;
    }
};