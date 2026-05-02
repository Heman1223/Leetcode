class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        int min = 0;

        for(int i = 0;i < n ; i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0;j < 4;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        fresh--;
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            if(!q.empty()) min++;
        }
        if(fresh == 0) return min;
        return -1;
    }
};