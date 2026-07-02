class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>> q; // Health, x,y
        
        if(grid[0][0] == 1) health--;
        if(health == 0) return false;
       

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        vector<vector<bool>> vis(n,vector<bool> (m,false));

        q.push({health ,{0,0}});
        vis[0][0] = true;

        while(!q.empty()){
            int h = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            if(x == n - 1 && y == m - 1 && h >= 1) return true;

            for(int i = 0;i < 4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == false){
                    vis[nx][ny] = true;
                    if(grid[nx][ny] == 1){
                        q.push({h - 1, {nx,ny}});
                    }else{
                        q.push({h, {nx,ny}});
                    }
                }
            }
        }
        return false;
    }
};