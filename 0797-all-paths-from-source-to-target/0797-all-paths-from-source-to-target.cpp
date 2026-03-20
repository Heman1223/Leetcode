class Solution {
public:
    void dfs(int node,int target,vector<int> &temp,vector<vector<int>> &ans,vector<vector<int>>& graph){
        temp.push_back(node);
        if(node == target) {
            ans.push_back(temp);
        }else{
            for(auto it : graph[node]){
                dfs(it,target,temp,ans,graph);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int V = graph.size();
        int target = V - 1;
        vector<int> temp;
        dfs(0,target,temp,ans,graph);
        return ans;
    }
};