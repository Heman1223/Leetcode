class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,vector<vector<int>> &dp){
        if(i == coins.size() || amount < 0){
            return 1e9;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        if(coins[i] > amount){
            return dp[i][amount] = solve(i + 1,coins,amount,dp);
        }
        int take = 1 + solve(i,coins,amount - coins[i],dp);
        int nottaken = solve(i + 1,coins,amount,dp);
        
        return dp[i][amount] = min(take,nottaken);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount + 1,-1));
        int ans = solve(0,coins,amount,dp);
        return ans == 1e9? -1 : ans;
        
        
    }
};