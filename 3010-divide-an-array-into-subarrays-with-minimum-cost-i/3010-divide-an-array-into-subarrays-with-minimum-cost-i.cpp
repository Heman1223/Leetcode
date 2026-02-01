class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int secm = 100;
        int min = 100;
        for(int i = 1;i < nums.size();i++){
            if(min > nums[i]){
                secm = min;
                min = nums[i];
            }else if(nums[i] < secm){
                secm = nums[i];
            }
        }
        return (nums[0] + min + secm);
    }
};