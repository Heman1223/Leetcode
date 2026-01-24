class Solution {
public:
    int minPairSum(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int maxPair = 0;
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            maxPair = max(maxPair, nums[left] + nums[right]);
            left++;
            right--;
        }

        return maxPair;
    }
};