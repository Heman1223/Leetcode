class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};