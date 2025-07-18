class Solution {
public:
    void dfs(vector<vector<char>> &mat,int i,int j,int row,int col){
        if(i == row || j == col || i < 0 || j < 0 || mat[i][j] == '0'){
            return;
        }
        mat[i][j] = '0';
        dfs(mat,i,j + 1,row,col);
        dfs(mat,i - 1,j,row,col);
        dfs(mat,i,j - 1,row,col);
        dfs(mat,i + 1,j,row,col);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,row,col);
                    ans++;
                }
            }
        }
        return ans;
    }
};