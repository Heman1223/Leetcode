class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q; //queue<vector<int>> q; (another way)
        int row = grid.size();
        int col = grid[0].size();
        
        int fresh = 0,rotten = 0;
        int min = 0;
        for(int i=0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    rotten++;
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
               vector<int> node = q.front();
                q.pop();
                for(int j = 0;j < 4;j++){
                    int x = node[0] + dx[j];
                    int y = node[1] + dy[j];
                    
                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1){
                        q.push({x,y});
                        grid[x][y] = 2;
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