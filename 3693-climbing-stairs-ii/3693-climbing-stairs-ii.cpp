class Solution {
public:
    int solve(int i, int n, vector<int>& costs,vector<int> &dp) {

        // Reached stair n
        if (i == n) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;

        // Jump 1
        if (i + 1 <= n) {
            ans = min(ans,
                solve(i + 1, n, costs,dp)
                + costs[i] + 1);
        }

        // Jump 2
        if (i + 2 <= n) {
            ans = min(ans,
                solve(i + 2, n, costs,dp)
                + costs[i + 1] + 4);
        }

        // Jump 3
        if (i + 3 <= n) {
            ans = min(ans,
                solve(i + 3, n, costs,dp)
                + costs[i + 2] + 9);
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1,-1);
        return solve(0, n, costs,dp);
    }
};