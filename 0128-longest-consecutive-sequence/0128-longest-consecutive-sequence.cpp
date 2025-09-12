class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        set<int> seq;
        for(int i = 0;i < nums.size();i++){
            seq.insert(nums[i]); 
        }
        for(int num : seq){
            if(seq.contains(num - 1)){
                continue;
            }else{
                int currNum = num;
                int currCount = 1;
                while(seq.contains(currNum + 1)){
                    currNum++;
                    currCount++;
                }
                count = max(count,currCount);
            }
        }
        return count;
    }
};