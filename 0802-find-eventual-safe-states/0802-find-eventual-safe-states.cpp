class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<vector<int>> adj(n);
        vector<int> outdoor(n,0);
        for(int i = 0 ; i < n ; i++){
            for(auto &it : graph[i]){
                adj[it].push_back(i);
                outdoor[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            if(outdoor[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int it : adj[node]){
                outdoor[it]--;
                if(outdoor[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};