class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26,false);
        vector<bool> upper(26,false);
        int count = 0;
        for(char i : word){
            if(i >= 'a' && i <= 'z'){
                lower[i - 'a'] = true;
            }else{
                upper[i - 'A'] = true;
            }
        }
        for(int i = 0; i < 26;i++){
            if(lower[i] && upper[i]){
                count++;
            }
        }
        return count;
    }
};