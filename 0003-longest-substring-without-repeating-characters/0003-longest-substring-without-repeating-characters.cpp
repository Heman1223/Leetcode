class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int size = s.size();
        unordered_set<char> st;
        while(right < size){
            char c = s[right];
            while(st.find(c) != st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(c);
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};