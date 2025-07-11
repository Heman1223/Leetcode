class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       vector<vector<int>> res;
        if(meetings.empty()) return 0;
       sort(meetings.begin(),meetings.end());
       res.push_back(meetings[0]);
       for(int i = 1;i<meetings.size();i++){
        vector<int> last = res.back();
         if(res.back()[1] >= meetings[i][0]) {
            res.back()[1] = max(res.back()[1], meetings[i][1]);
        }else{
            res.push_back(meetings[i]);
        }
       }
        for(int i = 0;i<res.size();i++){
            int workDay = (res[i][1] - res[i][0]) + 1;
            days = days - workDay;
        }
        return days;
    }
};