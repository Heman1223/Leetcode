class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1){
            return s.size();
        }
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> st;
        while(right < s.size()){
            char c = s[right];
            while(st.find(c) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }
};