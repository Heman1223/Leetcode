class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0;
        int r = n - 1;
        int pos = n - 1;
        while(l <= r){
            if(abs(nums[l]) < abs(nums[r])){
                ans[pos] = nums[r] * nums[r];
                pos--;
                r--;
            }else{
                ans[pos] = nums[l] * nums[l];
                pos--;
                l++;
            }
        }
        return ans;
    }
};