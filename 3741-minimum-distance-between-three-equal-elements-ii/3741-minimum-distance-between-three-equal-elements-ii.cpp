class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it : mp){
            if(mp[it.first].size() >= 3){
                for(int n = 0 ; n < it.second.size() - 2;n++){
                    int i = it.second[n];
                    int j = it.second[n + 1];
                    int k = it.second[n + 2];

                    int res = abs(i - j) + abs(j - k) + abs(k - i);
                    ans = min(ans,res);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};