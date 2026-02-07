class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = nums.size() - 1;
        int i = 0;
        while(i < j){
            if(nums[i] % 2 != 0){
                swap(nums[i],nums[j]);
                j--;
            }else{
                i++;
            }
        }
        return nums;
    }
};