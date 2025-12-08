class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int wsum = nums[0];
        int maxsum = nums[0];
        
        for(int right = 1; right < n; right++){
            wsum += nums[right];

            // compare nums[right] with previous element (avoids out-of-bounds)
            if(nums[right] <= nums[right - 1]) {
                maxsum = max(wsum - nums[right], maxsum);  
                wsum = nums[right];   // reset window
            }
        }
        
        // check last window
        maxsum = max(maxsum, wsum);

        return maxsum;
    }
};