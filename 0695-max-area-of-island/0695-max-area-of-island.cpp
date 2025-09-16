class Solution {
public:
    void dfs(int i,int j,int row, int col,vector<vector<int>>& grid,int &temp){
        if( i < 0 || j < 0 || i >=row || j >= col || grid[i][j] == 0){
            return;
        }
        temp++;
        grid[i][j] = 0;
        dfs(i + 1,j,row,col,grid,temp);
        dfs(i - 1,j,row,col,grid,temp);
        dfs(i,j + 1,row,col,grid,temp);
        dfs(i,j - 1,row,col,grid,temp);
        return;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        int temp = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1){
                    int temp = 0;
                    dfs(i,j,row,col,grid,temp);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};