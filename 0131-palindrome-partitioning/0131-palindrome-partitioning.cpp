class Solution {
public:
    bool palindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void func(int i, vector<string> &temp, vector<vector<string>> &ans, string &s){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(palindrome(s, i, j)){
                temp.push_back(s.substr(i, j - i + 1));
                func(j + 1, temp, ans, s);
                temp.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        func(0, temp, ans, s);
        return ans;
    }
};