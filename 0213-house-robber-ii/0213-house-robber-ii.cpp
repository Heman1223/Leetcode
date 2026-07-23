class Solution {
public:
    int solve(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i >= n ) return 0;
        if(dp[i] != -1) return dp[i];
        int l = nums[i] + solve(i + 2,nums,n,dp);
        int r = solve(i + 1,nums,n,dp);
        return dp[i] = max(l,r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> dp1(n,-1);
        vector<int> dp2(n + 1,-1);
        return max(solve(0,nums,n - 1,dp1), solve(1,nums,n,dp2));
    }
};