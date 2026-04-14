class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> nums;
        for(auto& it : intervals){
            nums.push_back({it[1],it[0]});
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        int last =  -1e9;
        for(auto& it : nums){
            int start = it.second;
            int end = it.first;
            if(start >= last){
                last = end;
            }else{
                count++;
            }
        }
        return count;
    }
};