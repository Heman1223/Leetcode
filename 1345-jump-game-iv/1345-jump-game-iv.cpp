class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // Step 1: Map each value to all its indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // Step 2: Initialize BFS queue and visited array
        queue<int> q;
        vector<bool> vis(n, false);
        
        q.push(0);
        vis[0] = true;
        int steps = 0;

        // Step 3: Standard BFS
        while (!q.empty()) {
            int size = q.size();
            
            for (int j = 0; j < size; j++) {
                int idx = q.front();
                q.pop();

                // Reached the last index
                if (idx == n - 1) return steps;

                // Option 1: Jump to indices with the same value
                int value = arr[idx];
                if (mp.count(value)) {
                    for (int nextIdx : mp[value]) {
                        if (!vis[nextIdx]) {
                            vis[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                    // Crucial: Clear the map entry to prevent redundant loops later
                    mp.erase(value); 
                }

                // Option 2: Jump to the next index (i + 1)
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // Option 3: Jump to the previous index (i - 1)
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }
            }
            steps++; // Increment step level after processing current layer
        }
        return -1;
    }
};
