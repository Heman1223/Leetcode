class Solution {
public:
    int solve(int i,int j,string &text1, string &text2,vector<vector<int>> &dp){
        if(i == text1.size() || j == text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
            return dp[i][j] =  1 + solve(i + 1,j + 1,text1,text2,dp);
        }
        int l = solve(i + 1,j,text1,text2,dp);
        int r = solve(i,j + 1,text1,text2,dp);
        return dp[i][j] = max(l,r);
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(s.size(),vector<int> (s2.size(),-1));
        int ans = solve(0,0,s,s2,dp);
        return ans;
    }
};