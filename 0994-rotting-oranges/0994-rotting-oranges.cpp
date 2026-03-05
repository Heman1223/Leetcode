class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        int min = 0;

        queue<pair<int,int>> q;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while(!q.empty()){
            int size = q.size();
            for(int j = 0 ; j < size;j++){
                pair<int,int> node = q.front();
                q.pop();
                for(int i = 0;i < 4;i++){
                    int x = dx[i] + node.first;
                    int y = dy[i] + node.second;
                    
                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1){
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty()) min++;
        }
        if(fresh == 0) return min;
        return -1;
    }
};