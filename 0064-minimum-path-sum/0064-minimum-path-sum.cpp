class Solution {
public:
    int solve(int i,int j,int r,int c,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i >= r || j >= c){
            return 1e9;
        }
        if(i == r - 1 && j == c - 1){
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = grid[i][j] + solve(i + 1,j,r,c,grid,dp);
        int right = grid[i][j] + solve(i ,j + 1,r,c,grid,dp);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        return solve(0,0,grid.size(),grid[0].size(),grid,dp);
    }
};