class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int zeroes = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0) zeroes++;
            while(zeroes > k && left <= i){
                if(nums[left] == 0){
                    zeroes--;
                }
                left++;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;
    }
};