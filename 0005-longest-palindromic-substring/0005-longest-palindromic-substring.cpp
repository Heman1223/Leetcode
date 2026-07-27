class Solution {
public:
    bool check(int i,int j,string &s,vector<vector<int>> &dp){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = check(i + 1,j - 1,s,dp);
        }
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int maxlen = 0;
        int stridx = 0;
        int n = s.size();
        if (n == 0) return "";
        vector<vector<int>> dp(n + 1,vector<int> (n + 1,-1));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int currlen = j - i + 1;
                if(check(i,j,s,dp)){
                    if(currlen > maxlen){
                        maxlen = currlen;
                        stridx = i;
                    }
                }
            }
        }
        return s.substr(stridx,maxlen);
    }
};