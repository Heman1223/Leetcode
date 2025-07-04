class Solution {
private:
    void function(string temp,vector<string> &ans,int open,int close,int n){
        if(temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }
        if(open < n){
            function(temp + "(",ans,open + 1,close,n);
        }
        if(open > close){
            function(temp + ")",ans,open,close + 1,n);
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function("",ans,0,0,n);
        return ans;
    }
};