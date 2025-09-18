class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<vector<int>> q;
        if(grid[0][0] == 1 || grid[row - 1][col - 1] == 1){
            return -1;
        }
        q.push({0,0});
        grid[0][0] = 1;
        int length = 1;

        vector<int> dx = {1,-1,0,0,1,1,-1,-1};
        vector<int> dy = {0,0,1,-1,1,-1,1,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i < size;i++){
                vector<int> node = q.front();
                q.pop();
                int xcurr = node[0];
                int ycurr = node[1];
                if(xcurr == row - 1 && ycurr == col - 1){
                    return length;
                }

                for(int j = 0 ; j < 8 ;j++){
                    int x = xcurr + dx[j];
                    int y = ycurr + dy[j];

                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
            length++;
        }
        return -1;
    }
};