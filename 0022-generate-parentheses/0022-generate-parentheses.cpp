class Solution {
public:
    void func(int open,int close,vector<string> &ans,string temp,int n){
        if(temp.size() == 2 * n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            func(open + 1,close,ans,temp + '(',n);
        }
        if(close < open){
            func(open,close + 1,ans,temp + ')',n);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        func(0,0,ans,temp,n);
        return ans;
    }
};