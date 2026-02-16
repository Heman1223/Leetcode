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
    int sumleft(TreeNode* root){
        if (!root) return 0;

        int sum = 0;

        // check if left child is a leaf
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag = true;
        int sum = sumleft(root);
        return sum;
    }
};