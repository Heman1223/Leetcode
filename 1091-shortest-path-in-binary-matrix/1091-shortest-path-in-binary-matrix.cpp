class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // ✅ If start or end cell is blocked, there is no possible path.
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) {
            return -1;
        }

        // ✅ BFS queue storing {row_index, col_index}
        queue<vector<int>> q;
        q.push({0, 0});          // push starting cell

        grid[0][0] = 1;          // mark starting cell as visited

        int count = 1;           // stores current path length (starts at 1 since (0,0) is included)

        // ✅ Direction vectors for 8 directions (N, S, E, W, NE, NW, SE, SW)
        vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, 1, -1};

        // ✅ Begin BFS
        while (!q.empty()) {
            int size = q.size();  // number of nodes at the current BFS level
            for (int i = 0; i < size; i++) {
                vector<int> node = q.front();
                q.pop();

                int x_curr = node[0];
                int y_curr = node[1];

                // ✅ If we reached the destination, return current path length
                if (x_curr == row - 1 && y_curr == col - 1) {
                    return count;
                }

                // ✅ Explore all 8 directions from the current cell
                for (int j = 0; j < 8; j++) {
                    int x = x_curr + dx[j];
                    int y = y_curr + dy[j];

                    // ✅ If within bounds and unvisited (cell == 0)
                    if (x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == 0) {
                        grid[x][y] = 1;      // mark as visited immediately
                        q.push({x, y});      // enqueue for next BFS level
                    }
                }
            }
            count++;  // ✅ Increment path length after processing the entire current level
        }

        // ✅ If BFS completes without reaching the destination, return -1
        return -1;
    }
};