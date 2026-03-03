class Solution {
public:
    void dfs(vector<vector<char>> &grid,int row,int col,int i,int j){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0';
        dfs(grid,row, col, i + 1, j);
        dfs(grid,row, col, i - 1, j);
        dfs(grid,row, col, i , j + 1);
        dfs(grid,row, col, i , j - 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0 ; i < grid.size();i++){
            for(int j = 0 ; j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,grid.size(),grid[0].size(),i,j);
                }
            }
        }
        return count;
    }
};