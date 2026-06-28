class Solution {
public:
    int func(vector<int> &nums,int k){
        unordered_map<int,int> mp;
        int left = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(mp[nums[i]] == 0) k--;
            mp[nums[i]]++;

            while(k < 0){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) k++;
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k) - func(nums, k - 1);
    }
};