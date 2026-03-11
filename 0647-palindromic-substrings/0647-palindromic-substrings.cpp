class Solution {
public:
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!= s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            for(int j = i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};