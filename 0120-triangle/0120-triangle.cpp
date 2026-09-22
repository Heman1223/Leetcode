class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& memo) {
        int n = triangle.size();
        
        // Base case: leaf nodes on the bottom row
        if (i == n - 1) {
            return triangle[i][j];
        }

        if (memo[i][j] != -1e9) {
            return memo[i][j];
        }

        // Two valid next moves: (i + 1, j) and (i + 1, j + 1)
        int down = solve(i + 1, j, triangle, memo);
        int diag = solve(i + 1, j + 1, triangle, memo);

        return memo[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1e9));
        return solve(0, 0, triangle, memo);
    }
};