class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX, j = k - 1;
        for(int i = 0;i + j < n ;i++){
            ans = min(abs(nums[i] - nums[i + j]), ans );
        }
        return ans;
    }
};