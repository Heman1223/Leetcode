class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string,int> mp;
        for(int i = 0;i < arr1.size();i++){
            string s = to_string(arr1[i]);
            string str = "";
            for(int j = 0;j < s.size();j++){
                str += s[j];
                mp[str] = str.size();
            }
        }
        for(int i = 0;i < arr2.size();i++){
            string str = to_string(arr2[i]);
            string s = "";
            for(int j = 0; j < str.size();j++){
                s += str[j];
                if(mp.count(s)){
                    ans = max(ans,mp[s]);
                }
            }
        }
        return ans;
    }
};