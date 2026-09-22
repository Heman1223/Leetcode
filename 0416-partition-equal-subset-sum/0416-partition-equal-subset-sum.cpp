class Solution {
public:
    bool solve(int i,int totalsum,vector<int>& nums,vector<vector<int>> &dp){
        if(totalsum == 0) return true;
        if(i >= nums.size() || totalsum < 0){
            return false;
        }
        if(dp[i][totalsum] != -1) return dp[i][totalsum];
        bool l = solve(i + 1,totalsum - nums[i],nums,dp);
        bool r = solve(i + 1,totalsum,nums,dp);
        
        return dp[i][totalsum] = l || r;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int x : nums) totalSum += x;
        if(totalSum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(),vector<int> (totalSum,-1));
        return solve(0,totalSum / 2,nums,dp);
    }
};