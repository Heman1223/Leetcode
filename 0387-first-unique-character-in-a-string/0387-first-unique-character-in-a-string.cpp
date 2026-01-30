class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> seen(256,0);
        for(char i : s){
            seen[i]++;
        }
        for(int i = 0 ;i < s.length();i++){
            if(seen[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};