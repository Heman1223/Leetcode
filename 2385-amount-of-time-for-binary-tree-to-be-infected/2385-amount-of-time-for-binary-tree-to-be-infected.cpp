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
    int amountOfTime(TreeNode* root, int start) {
        // Step 1: Build an undirected adjacency list graph using a map
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                adj[curr->val].push_back(curr->left->val);
                adj[curr->left->val].push_back(curr->val); // Undirected link
                q.push(curr->left);
            }
            if (curr->right) {
                adj[curr->val].push_back(curr->right->val);
                adj[curr->right->val].push_back(curr->val); // Undirected link
                q.push(curr->right);
            }
        }

        // Step 2: BFS from the start node to find max distance
        queue<int> qu;
        unordered_set<int> visited; // Track visited nodes properly

        qu.push(start);
        visited.insert(start);
        int minutes = -1; // Start at -1 because the initial state takes 0 minutes

        while (!qu.empty()) {
            int size = qu.size();
            minutes++; // Increment time for each layer of infection

            for (int i = 0; i < size; i++) {
                int curr = qu.front();
                qu.pop();

                for (int neighbor : adj[curr]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        qu.push(neighbor);
                    }
                }
            }
        }

        return minutes;
    }
};