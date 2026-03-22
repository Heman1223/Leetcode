class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            if(x == rows - 1 && y == cols - 1) return effort;
            for(int i = 0;i < 4 ;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < rows && newy >= 0 && newy < cols){
                    int newEffort = max(effort,abs(heights[x][y] - heights[newx][newy]));

                    if(newEffort < dist[newx][newy]){
                        dist[newx][newy] = newEffort;
                        pq.push({newEffort,{newx,newy}});
                    }
                }
            }
        }
        return 0;
    }
};