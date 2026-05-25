class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> outdegree(V);
        vector<vector<int>> adj(V);
        for(int i = 0;i < V;i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                outdegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0;i < V;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                outdegree[it]--;
                if(outdegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};