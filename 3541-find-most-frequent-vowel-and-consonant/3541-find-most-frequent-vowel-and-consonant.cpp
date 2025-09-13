class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26],mv = 0,mc = 0;
        for(char c : s){
            int i = c - 'a';
            freq[i]++;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                mv = max(mv,freq[i]);
            }else{
                mc = max(mc,freq[i]);
            }
        }
        return mv + mc;
    }
};