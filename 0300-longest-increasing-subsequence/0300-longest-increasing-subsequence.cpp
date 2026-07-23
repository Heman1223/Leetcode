class Solution {
public:
    int solve(int prev,int i,vector<int> &nums,int n,vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int nottake = solve(prev,i + 1,nums,n,dp);
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            take = 1 + solve(i,i + 1,nums,n,dp);
        }
        return dp[i][prev + 1] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int> (n + 1,-1));
        return solve(-1,0,nums,n,dp);
    }
};