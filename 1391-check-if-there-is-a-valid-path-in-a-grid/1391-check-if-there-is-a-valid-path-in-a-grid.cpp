class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // For each street type, store the directions it can move in
        // (dr, dc) = (delta row, delta col)
        vector<vector<pair<int,int>>> directions(7);

        directions[1] = {{0,-1}, {0,1}};    // left, right
        directions[2] = {{-1,0}, {1,0}};    // up, down
        directions[3] = {{0,-1}, {1,0}};    // left, down
        directions[4] = {{0,1}, {1,0}};     // right, down
        directions[5] = {{0,-1}, {-1,0}};   // left, up
        directions[6] = {{0,1}, {-1,0}};    // right, up

        queue<pair<int,int>> q;

        // visited array to avoid revisiting cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // start BFS from top-left cell
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // if we reached bottom-right, path is valid
            if (r == m - 1 && c == n - 1)
                return true;

            // explore all valid directions from current cell
            for (auto [dr, dc] : directions[grid[r][c]]) {
                int nr = r + dr;
                int nc = c + dc;

                // check bounds and visited
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc])
                    continue;

                // check if next cell connects back to current cell
                for (auto [back_dr, back_dc] : directions[grid[nr][nc]]) {
                    // if moving from next cell leads back to current cell
                    if (nr + back_dr == r && nc + back_dc == c) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                        break; // no need to check other directions
                    }
                }
            }
        }

        // if BFS ends without reaching destination
        return false;
    }
};