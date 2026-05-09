class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        int count = 1;
        grid[0][0] = 1;

        int dx[] = {0,0,1,-1,1,1,-1,-1};
        int dy[] = {1,-1,0,0,1,-1,1,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n - 1 && y == n - 1){
                    return count;
                }
                for(int j = 0;j < 8;j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};