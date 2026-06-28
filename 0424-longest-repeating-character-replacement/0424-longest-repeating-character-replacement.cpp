class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxoccur = 0;
        int ans = 0;
        vector<int> freq(26,0);
        for(int i = 0;i < s.size();i++){
            maxoccur = max(maxoccur,++freq[s[i] - 'A']);
            while(i - left + 1 - maxoccur > k && left <= i){
                freq[s[left] - 'A']--;
                left++;
            }
            ans = max(i - left + 1,ans);
        }
        return ans;
    }
};