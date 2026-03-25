class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long> dist(n,1e18);
        vector<int> ways(n,0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;

        int mod = 1e9 + 7;

        while(!pq.empty()){

            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){

                int adjNode = it.first;
                int adjTime = it.second;

                if(time + adjTime < dist[adjNode]){

                    dist[adjNode] = time + adjTime;

                    pq.push({dist[adjNode],adjNode});

                    ways[adjNode] = ways[node];
                }

                else if(time + adjTime == dist[adjNode]){

                    ways[adjNode] =
                    (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};