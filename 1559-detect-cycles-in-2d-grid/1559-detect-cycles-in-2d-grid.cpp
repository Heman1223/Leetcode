class Solution {
public:
    int m, n;

    bool dfs(int r, int c, int pr, int pc,
             vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        // 4 possible directions: up, down, left, right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // check bounds
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            // must have same character
            if (grid[nr][nc] != grid[r][c])
                continue;

            // skip the parent cell
            if (nr == pr && nc == pc)
                continue;

            // if already visited -> cycle found
            if (visited[nr][nc])
                return true;

            // continue DFS
            if (dfs(nr, nc, r, c, grid, visited))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // try DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited))
                        return true;
                }
            }
        }

        return false;
    }
};