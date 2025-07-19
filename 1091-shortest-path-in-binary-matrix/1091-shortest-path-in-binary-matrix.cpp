class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1){
            return -1;
        }
        vector<vector<int>> dp(row,vector<int> (col,0));
        queue<vector<int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int count = 1;
        vector<int> dx = {0,0,1,-1,1,1,-1,-1};
        vector<int> dy = {1,-1,0,0,1,-1,1,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                vector<int> node = q.front();
                q.pop();
                if(node[0] == row - 1 && node[1] == col - 1) return count;
                for(int j = 0;j < 8;j++){
                    int x = node[0] + dx[j];
                    int y = node[1] + dy[j];

                    if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.push({x,y});
                        
                    }
                    
                }
            }
            count++;
        }
        return -1;
    }
};