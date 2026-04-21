class Solution {
public:
    int revers(int num){
        string s = to_string(num);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int rev = revers(nums[i]);

            if(mp.count(nums[i])){
                ans = min(ans, i - mp[nums[i]]);
            }

            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};