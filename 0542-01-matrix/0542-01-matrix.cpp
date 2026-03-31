class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty()){
            int currx = q.front().first.first;
            int curry = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[currx][curry] = steps;

            for(int i = 0;i < 4;i++){
                int nextx = currx + dx[i];
                int nexty = curry + dy[i];

                if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && vis[nextx][nexty] == 0){
                    q.push({{nextx,nexty}, steps + 1});
                    vis[nextx][nexty] = 1;
                }
            }
        }
        return dist;
    }
};