class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int count = 0;
        for(int num : st){
            if(st.contains(num - 1)){
                continue;
            }
            else{
                int currnum = num;
                int currcount = 1;
                while(st.contains(currnum + 1)){
                    currnum++;
                    currcount++;
                }
                count = max(count,currcount);
            }
        }
        return count;
    }
};