class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int min = 0;

        for(int i = 0 ; i < rows;i++){
            for(int j = 0;j < cols;j++){
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
            for(int i = 0 ; i < size;i++){
                auto it = q.front();
                int currx = it.first;
                int curry = it.second;
                q.pop();
                for(int j = 0;j < 4;j++){
                    int nextx = dx[j] + currx;
                    int nexty = dy[j] + curry;

                    if(nexty >= 0 && nextx >= 0 && nextx < rows && nexty < cols && grid[nextx][nexty] == 1){
                        grid[nextx][nexty] = 2;
                        q.push({nextx,nexty});
                        fresh--;
                    }
                }
            }
            if(!q.empty()) min++;
        }
        if(fresh == 0) return min;
        return -1;
    }
};