class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> dp = matrix;

        for(int i = 1; i < r; i++) {
            for(int j = 0; j < c; j++) {

                int left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int up = dp[i-1][j];
                int right = (j < c-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] += min({left, up, right});
            }
        }

        return *min_element(dp[r-1].begin(), dp[r-1].end());
    }
};