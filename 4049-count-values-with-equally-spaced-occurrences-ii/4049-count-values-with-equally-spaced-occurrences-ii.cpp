class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto &it : mp){
            auto &i = it.second;
            int n = i.size();
            if(n < 3) continue;
            int diff = i[1] - i[0];
            bool flag = true;
            for(int j = 2;j < n;j++){
                if((i[j] - i[j - 1]) != diff){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans++;
            } 
        }
        return ans;
    }
};