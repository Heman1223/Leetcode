class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);

        q.push({0,{src,0}}); //steps, node, dist

        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            int steps = it.first;
            int node = it.second.first;
            int nodeW = it.second.second;

            q.pop();

            if(steps > k) continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                if(nodeW + edW < dist[adjNode] && steps <= k){
                    dist[adjNode] = nodeW + edW;
                    q.push({steps + 1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};