class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> vis(256, false);
        int ans = 0;
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            while (vis[s[i]]) {
                vis[s[j]] = false;
                j++;
            }
            vis[s[i]] = true;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};