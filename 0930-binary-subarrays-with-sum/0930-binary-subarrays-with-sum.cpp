class Solution {
public:
    int func(vector<int>& nums,int goal){
        if(goal < 0) return 0;

        int l = 0,sum = 0,count = 0;
        for(int r = 0;r < nums.size();r++){
            sum += nums[r];
            
            while(sum > goal && l <= r){
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums,goal) - func(nums,goal - 1);
    }
};