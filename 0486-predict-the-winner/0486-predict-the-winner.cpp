class Solution {
public:
    int helper(vector<int>& nums,int i,int j){
        if(i == j){
            return nums[i];
        }
        int pickLeft = nums[i] - helper(nums,i + 1,j);
        int pickRight = nums[j] - helper(nums,i,j - 1);
        return max(pickLeft,pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n - 1) >= 0;
    }
};