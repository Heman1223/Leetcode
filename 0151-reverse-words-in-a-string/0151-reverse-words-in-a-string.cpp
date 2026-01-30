class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string str = "";
        for(char i : s){
            if(isalnum(i)){
                str += i;
            }else if(i == ' '){
                if(str.length() == 0){
                    continue;
                }
                arr.push_back(str);
                str = "";
            }
        }
        if(str.length() != 0){
            arr.push_back(str);
        }
        string ans = "";
        for(int i = arr.size() - 1;i > 0;i--){
            ans = ans + arr[i] + " ";
        }
        ans = ans + arr[0];
        return ans;
    }
};