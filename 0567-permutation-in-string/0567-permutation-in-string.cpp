class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char,int> mp;
        for(char c : s1){
            mp[c]++;
        }
        int k = s1.size();
        unordered_map<char,int> mp1;
        for(int i = 0;i < s1.size();i++){
            mp1[s2[i]]++;
        }
        if(mp1 == mp) return true;
        for(int i = k;i < s2.size();i++){
            mp1[s2[i - k]]--;
            if(mp1[s2[i - k]] == 0){
                mp1.erase(s2[i - k]);
            }
            mp1[s2[i]]++;
            if(mp == mp1) return true;
        }
        return false;
    }
};