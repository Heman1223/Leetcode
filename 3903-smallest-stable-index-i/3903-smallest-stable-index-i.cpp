class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxn = -1e9;

        int n = nums.size();
        vector<int> prefix(n);
        prefix[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--){
            prefix[i] = min(nums[i],prefix[i + 1]);
        }
        for(int i = 0;i < n;i++){
            maxn = max(nums[i],maxn);
            if(maxn - prefix[i] <= k){
                return i;
            }
        }
        return -1;
    }
};