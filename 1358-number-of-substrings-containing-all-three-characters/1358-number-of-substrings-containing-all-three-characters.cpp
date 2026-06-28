class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int left = 0;
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
            while(mp.size() == 3 && left <= i){
                ans += (s.size() - i);
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};