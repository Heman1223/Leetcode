class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n,vector<int> (m,0));
        vector<vector<int>> vis(n,vector<int> (m,0));

        queue<pair<int,int>> q;
        for(int i = 0 ;i < n;i++ ){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size;i++){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                int dst = dist[x][y];
                q.pop();

                for(int j = 0 ; j < 4 ;j++){
                    int currx = dx[j] + x;
                    int curry = dy[j] + y;
                    if(currx >= 0 && currx < n && curry >= 0 && curry < m && vis[currx][curry] == 0){
                        vis[currx][curry] = 1;
                        dist[currx][curry] = dst + 1;
                        q.push({currx,curry});
                    } 
                }
            }
        }
        return dist;
    }
};