class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
       vector<vector<int>> ans;
      
      if(intervals.size() <= 1){
        return intervals;
      }
       for(int i=0;i<intervals.size() - 1;i++){
        vector<int> temp;
        if(intervals[i][1] >= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][1]){
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
            i++;
            continue;
        }
        else if(intervals[i][1] >= intervals[i + 1][0] && intervals[i][1] <= intervals[i + 1][1]){
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i + 1][1]);
            ans.push_back(temp);
            i++;
            continue;
        }else{
            ans.push_back(intervals[i]);
            ans.push_back(intervals[i + 1]);
        }
       }
       return ans;

    }
};