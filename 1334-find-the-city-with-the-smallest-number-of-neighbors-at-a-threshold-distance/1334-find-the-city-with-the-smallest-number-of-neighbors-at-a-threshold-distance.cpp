class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int> (n,1e9));
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int ans = -1;
        int mincnt = INT_MAX;
        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                if(i !=j && matrix[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= mincnt){
                mincnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};