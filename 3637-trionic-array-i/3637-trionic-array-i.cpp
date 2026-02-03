class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag1 = false, flag2 = false, flag3 = false;
        int i = 0;
        while(i < nums.size() - 1 && nums[i] < nums[i + 1]){
            i++;
            flag1 = true;
        }
        while(i < nums.size() - 1 && nums[i] > nums[i + 1]){
            i++;
            flag2 = true;
        }
        while(i < nums.size() - 1 && nums[i] < nums[i + 1]){
            i++;
            flag3 = true;
        }
        return (flag1 && flag2 && flag3) && (i == nums.size() - 1);
    }
};