class Solution {
public:
    int solve(int i,int j, vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp,int m,int n){
        if(i >= m || j >= n){
            return 0;
        }
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = (solve(i,j + 1,obstacleGrid,dp,m,n) + solve(i + 1,j,obstacleGrid,dp,m,n));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,obstacleGrid,dp,m,n);
    }
};