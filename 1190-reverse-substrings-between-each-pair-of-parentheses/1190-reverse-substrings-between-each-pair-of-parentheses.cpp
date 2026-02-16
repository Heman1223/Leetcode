class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;
        for(char i : s){
            st.push(i);
            if(st.top() == ')'){
                st.pop();
                string temp = "";
                while(st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(char c : temp){
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};