class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(),0);

        for(int i=heights.size()-1;i>=0;i--){
        int cnt = 0;
            while(!st.empty() && heights[st.top()]<=heights[i]){
                st.pop();
                cnt++;
            }
            if(!st.empty()) cnt++;
            ans[i] = cnt;
            st.push(i);
        }

        return ans;
    }
};