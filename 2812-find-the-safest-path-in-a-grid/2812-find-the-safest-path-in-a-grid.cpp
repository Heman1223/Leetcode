class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   dist[nx][ny] == INT_MAX) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        // Max heap: {current safeness, {x, y}}
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0, 0}});
        best[0][0] = dist[0][0];

        while(!pq.empty()) {
            auto [sf, cell] = pq.top();
            pq.pop();

            int x = cell.first;
            int y = cell.second;

            // First time reaching destination is optimal
            if(x == n - 1 && y == n - 1)
                return sf;

            if(sf < best[x][y]) continue;

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n) {

                    int newSF = min(sf, dist[nx][ny]);

                    if(newSF > best[nx][ny]) {
                        best[nx][ny] = newSF;
                        pq.push({newSF, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};