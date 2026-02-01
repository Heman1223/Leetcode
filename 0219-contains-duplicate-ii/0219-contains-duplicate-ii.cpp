class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int,int> mp;
        int val;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                val = abs(i-mp[nums[i]]);
                if(val<=k) return true;
               
            }
            mp[nums[i]] = i;
            
        }
        return false;
    }
};