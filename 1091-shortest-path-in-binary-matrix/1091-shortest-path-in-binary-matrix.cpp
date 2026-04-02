class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1){
            return -1;
        }
        int count = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        vector<int> dx = {1,-1,0,0,1,1,-1,-1};
        vector<int> dy = {0,0,1,-1,1,-1,1,-1};
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == row - 1 && y == col - 1){
                    return count;
                }
                for(int j = 0; j < 8;j++){
                    int currx = x + dx[j];
                    int curry = y + dy[j];
                    if(currx >= 0 && currx < row && curry >= 0 && curry < col && grid[currx][curry] == 0){
                        grid[currx][curry] = 1;
                        q.push({currx,curry});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};