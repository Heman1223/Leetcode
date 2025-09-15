class Solution {
public:
    void DFS(int i,vector<vector<int>> adj,vector<int> &vis){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                DFS(it,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        //To change Matrix to Adjacency List
        for(int i = 0; i < V ; i++){
            for(int j = 0; j < V ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int cnt = 0;
        for(int i = 0; i < V ; i++){
            if(!vis[i]){
                cnt++;
                DFS(i,adj,vis);
            }
        }
        return cnt;
    }
};