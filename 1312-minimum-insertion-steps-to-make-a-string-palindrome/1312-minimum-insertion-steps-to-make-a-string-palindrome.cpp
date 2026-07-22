class Solution {
public:
    int lps(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + lps(i + 1,j + 1,s1,s2,dp);
        }
        int l = lps(i + 1,j, s1,s2,dp);
        int r = lps(i ,j + 1,s1,s2,dp);
        return dp[i][j] = max(l,r);
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int> (s.size(),-1));
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s.size() - lps(0,0,s,s2,dp);
    }
};