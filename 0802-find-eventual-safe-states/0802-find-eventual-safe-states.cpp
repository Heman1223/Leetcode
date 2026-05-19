class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revadj(V);
        vector<int> outdegree(V,0);
        for(int i = 0;i < V;i++){
            for(auto it : graph[i]){
                revadj[it].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0;i < V;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: revadj[node]){
                outdegree[it]--;
                if(outdegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};