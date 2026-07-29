class Solution {
public:
    int dp[51][51][51][51];
    int solve(int i1,int j1,int i2,int j2,int n,vector<vector<int>> &grid){
        if(i1 == n || i2 == n || j1 == n || j2 == n){
            return INT_MIN;
        }
        if(i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1){
            return grid[i1][j1];
        }
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        int cherry = 0;
        if(grid[i1][j1] == -1) return INT_MIN;
        if(grid[i2][j2] == -1) return INT_MIN;

        if(i1 == i2 && j1 == j2){
            cherry += grid[i1][j1];
        }else{
            cherry += grid[i1][j1] + grid[i2][j2];
        }

        return dp[i1][j1][i2][j2] = cherry + max(solve(i1 + 1,j1,i2 + 1,j2,n,grid),max(solve(i1,j1 + 1,i2 + 1,j2,n,grid),max(solve(i1 + 1,j1,i2,j2 + 1,n,grid),solve(i1,j1 + 1,i2,j2 + 1,n,grid))));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        int res = solve(0,0,0,0,n,grid);
        return max(res,0);
    }
};