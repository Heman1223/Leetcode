class Solution {
public:
    void dfs(int i,int j,int row,int col,vector<vector<int>>& grid,int &temp,bool &touchesboundary){
        if(i < 0 || j < 0 || i >= row - 1 || j >= col - 1 || grid[i][j] == 0){
            return;
        }
        temp++;
        grid[i][j] = 0;
        if(i == 0 || j == 0 || i == row - 1 || j == col - 1){
            touchesboundary = true;
        }
        
        dfs(i + 1,j,row,col,grid,temp,touchesboundary);
        dfs(i - 1,j,row,col,grid,temp,touchesboundary);
        dfs(i,j + 1,row,col,grid,temp,touchesboundary);
        dfs(i,j - 1,row,col,grid,temp,touchesboundary);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < row ; i++){
            for(int  j = 0; j < col ; j++){
                if(grid[i][j] == 1){
                    int temp = 0;
                    bool touchesboundary = false;
                    dfs(i,j,row,col,grid,temp,touchesboundary);
                    if(!touchesboundary) ans += temp;
                }
            }
        }
        return ans;
    }
};