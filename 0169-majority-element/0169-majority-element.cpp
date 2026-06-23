class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];

        for(int num : nums){
            if(ele == num){
                count++;
            }else{
                count--;
            }
            if(count < 0){
                ele = num;
                count = 1;
            }
        }
        return ele;
    }
};