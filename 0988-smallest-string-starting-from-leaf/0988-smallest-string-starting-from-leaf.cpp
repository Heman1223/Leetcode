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
     void function(TreeNode* root, string temp, string &ans) {
        if (!root) return;

        temp += ('a' + root->val);

        if (!root->left && !root->right) {
            string curr = temp;
            reverse(curr.begin(), curr.end());
            if (ans.empty() || curr < ans) {
                ans = curr;
            }
        }

        function(root->left, temp, ans);
        function(root->right, temp, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        function(root,"",ans);
        return ans;
    }
};