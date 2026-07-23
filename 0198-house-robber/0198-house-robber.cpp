class Solution {
public:
    int solve(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int l = nums[i] + solve(i + 2,nums,n,dp);
        int r = solve(i + 1,nums,n,dp);
        return dp[i] = max(l,r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1,-1);
        return solve(0,nums,n,dp);
    }
};