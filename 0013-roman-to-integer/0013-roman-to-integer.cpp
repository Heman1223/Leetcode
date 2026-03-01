class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int num = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(i==s.size()-1){
                num+= mp[s[i]];
            }
            else if(mp[s[i+1]]<=mp[s[i]]){
                num += mp[s[i]];
            }
            else{
                num -= mp[s[i]];
            }
        }

         return num;
    }
};