class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxsum = INT_MIN;
        int sum = 0;
        while (j < n){
            sum += nums[j++];
            maxsum = max(maxsum,sum);
            if(sum < 0){
                i++;
                j = i;
                sum = 0;
            }
        }
        return maxsum;
    }
};