class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,bool> mp;
        int j = 0;
        for(int i = 0; i < s.size();i++){
            char c = s[i];
            while(mp[c] == true){
                char ch = s[j];
                mp[ch] = false;
                j++;
            }
            mp[c] = true;
            ans = max(ans,i - j + 1);
        }
        return ans;
    }
};