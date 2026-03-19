class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V);
        vector<vector<int>> revadj(V);
        for(int i = 0;i < V;i++){
            for(auto it : graph[i]){
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0;i < V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : revadj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};