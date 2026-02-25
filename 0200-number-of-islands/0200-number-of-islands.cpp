class Solution {
public:
    void dfs(int i,int j,int row,int col,vector<vector<char>>& grid){
        if(i >= row || j >= col || i < 0 || j < 0 || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(i + 1,j,row,col,grid);
        dfs(i - 1,j,row,col,grid);
        dfs(i ,j + 1,row,col,grid);
        dfs(i ,j - 1,row,col,grid);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0;j < col ; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,row,col,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};