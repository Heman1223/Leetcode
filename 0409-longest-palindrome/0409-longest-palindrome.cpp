class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int k = -1;
        for(char c : s){
            mp[c]++;
        } 
        for(auto it : mp){
            if(it.second%2 != 0 ) k++;
        }
        if(k == -1) k = 0;
        return s.size() - k;
    }
};