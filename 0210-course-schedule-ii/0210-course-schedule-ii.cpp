class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i < numCourses;i++){
            for(auto &edge : prerequisites){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
            }
        }
        vector<int> inDegree(numCourses,0);
        for(int i = 0;i < numCourses;i++){
            for(int it : adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(topo.size() != numCourses) return {};
        reverse(topo.begin(),topo.end());
        return topo;

    }
};