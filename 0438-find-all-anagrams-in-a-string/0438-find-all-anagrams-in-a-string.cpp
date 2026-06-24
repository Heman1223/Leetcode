class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size(), m = p.size();
        if (n < m) return ans;

        vector<int> pFreq(26, 0), winFreq(26, 0);

        for (char c : p)
            pFreq[c - 'a']++;

        for (int i = 0; i < n; i++) {
            winFreq[s[i] - 'a']++;

            // Keep window size = m
            if (i >= m)
                winFreq[s[i - m] - 'a']--;

            // Compare frequencies
            if (i >= m - 1 && winFreq == pFreq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};