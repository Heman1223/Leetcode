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
    long long total = 0;
    long long best = 0;
    static const int MOD = 1e9 + 7;

    // Step 1: compute total sum of tree
    void totalsum(TreeNode* root) {
        if (!root) return;
        total += root->val;
        totalsum(root->left);
        totalsum(root->right);
    }

    // Step 2: compute subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);
            
        long long subSum = left + right + root->val;

        // Try splitting here
        best = max(best, subSum * (total - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalsum(root);   // total sum of tree
        dfs(root);        // compute max product
        return best % MOD;
    }
};