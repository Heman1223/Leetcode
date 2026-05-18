class Solution {
public:
    string convert(string s, int numRows) {
        unordered_map<int,string> mp;
        if(numRows == 1){
            return s;
        }
        int row = 0;
        bool flag = true;
        for(int i = 0; i < s.size();i++){
            mp[row].push_back(s[i]);
            if(flag){
                row++;
            }else{
                row--;
            }
            if(row == numRows || row == -1){
                flag = !flag;
            }
            
            if(row == numRows){
                row = numRows - 2;
            }
            if(row == -1){
                row = 1;
            }
        }
        string ans = "";
        for(int i = 0;i < numRows;i++){
            ans += mp[i];
        }
        return ans;
    }
};