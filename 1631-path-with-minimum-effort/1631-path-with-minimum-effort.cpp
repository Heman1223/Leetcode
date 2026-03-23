class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(rows,vector<int>(cols,1e9));

         pq.push({0,{0,0}});
         dist[0][0] = 0;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!pq.empty()){
            auto it = pq.top();
            int effort = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            pq.pop();

            if(currx == rows - 1 && curry == cols - 1){
                return effort;
            }
            for(int i = 0;i < 4;i++){
                int nextx = currx + dx[i];
                int nexty = curry + dy[i];
                if(nextx >= 0 && nextx < rows && nexty >= 0 && nexty < cols){
                    int maxeffort = max(effort,abs(heights[currx][curry] - heights[nextx][nexty]));
                    if(maxeffort < dist[nextx][nexty]){
                        dist[nextx][nexty] = maxeffort;
                        pq.push({maxeffort,{nextx,nexty}});
                    }
                }
            }
        }
        return 0;
    }
};