class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &x,vector<int>& y){
            if(x[0] == y[0]){
                return x[1] > y[1];
            }
            return x[0] < y[0];
        });
        
        int ans = 0;

        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i = 1;i < intervals.size();i++){
            
            int c = intervals[i][0];
            int d = intervals[i][1];

            if(c >= a && b >= d){
                ans++;
            }else{
                a = c;
                b = d;
            }
        }
        return intervals.size() - ans;
    }
};