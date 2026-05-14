class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int,int> mp;
        int maxe = INT_MIN;
        bool flag = false;
        for(int i : nums){
            mp[i]++;
            if(mp[i] == 2 && flag) return false;
            if(mp[i] == 2 && !flag) flag = true;
    
            maxe = max(i,maxe);
        }
        int n = nums.size();
        if(maxe == n - 1 && mp[maxe] == 2) return true;
        return false;
    }
};