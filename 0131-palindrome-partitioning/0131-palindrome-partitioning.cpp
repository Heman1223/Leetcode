class Solution {
private:
    bool isPalindrome(string s,int start,int end){
        
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void function(string s,vector<string> comb,vector<vector<string>>& ans,int start){
        if(start == s.size()){
            ans.push_back(comb);
            return;
        }
        for(int i = start; i < s.size(); i++) {  // fixed start index
            if(isPalindrome(s, start, i)) {
                comb.push_back(s.substr(start, i - start + 1));
                function(s, comb, ans, i + 1);
                comb.pop_back();
            }
        }
    }
 
public:
    vector<vector<string>> partition(string s) {
        vector<string> comb;
        vector<vector<string>> ans;
        function(s,comb,ans,0);
        return ans;
    }
};