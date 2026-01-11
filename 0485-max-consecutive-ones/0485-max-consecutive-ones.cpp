class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                ans = max(curr,ans);
                curr = 0;
            }
            curr++;
        }
        ans = max(curr,ans);
        return ans - 1;
    }
};