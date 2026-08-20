class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(i == coins.size() || amount < 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = solve(i,amount - coins[i],coins,dp);
        int notTake = solve(i + 1,amount,coins,dp);
        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount + 1,-1));
        return solve(0,amount,coins,dp);
    }
};