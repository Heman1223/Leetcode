class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<vector<int>> &adj,vector<int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,pathvis)){
                    return true;
                }
            }else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int> vis(numCourses);
        vector<int> pathvis(numCourses);
        for(int i = 0 ; i < numCourses ;i++){
            if(!vis[i]){
                if(dfs(i,vis,adj,pathvis)){
                    return false;
                }
            }
        }
        return true;
    }
};