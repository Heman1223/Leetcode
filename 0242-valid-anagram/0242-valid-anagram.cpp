class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; 
        unordered_map<char,int> mp;
        for(char x : s){
            mp[x] += 1;
        }
        for(char x : t){
            if(mp[x] > 0){
                mp[x]--;
            }else{
                return false;
            }
        }
        return true;
    }
};