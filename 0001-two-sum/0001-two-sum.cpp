class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            //a(nums[i]) + b = target
            //b = target - a (nums[i])
            int b = target - nums[i];
            if(mp.count(b)){
                return {mp[b],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};