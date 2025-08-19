class Solution {
public:
    void solve(int n,string temp,vector<string> &ans,int open,int close){
        if(temp.size() == n * 2){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            solve(n,temp + "(",ans,open + 1,close);
        }
        if(close < open){
            solve(n,temp + ")",ans,open,close + 1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,"",ans,0,0);
        return ans;
    }
};