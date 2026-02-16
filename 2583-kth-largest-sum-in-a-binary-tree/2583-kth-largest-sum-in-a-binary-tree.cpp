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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return -1;
        vector<long long> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            
            long long s = 0;
            for(int i = 0; i < size;i++){
                TreeNode* temp = q.front();
                q.pop();
                s += temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            sum.push_back(s);
        }
        sort(sum.begin(),sum.end());
        if(k > sum.size()) return -1;
        long long ans = sum[sum.size() - k];
        return ans;
        
    }
};