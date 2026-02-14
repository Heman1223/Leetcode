class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        for(int i = 0 ; i < operations.size();i++){
            if(operations[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }else if(operations[i] == "D"){
                int a = st.top();
                st.push(a * 2);
            }else if(operations[i] == "C"){
                st.pop();
            }else{
                st.push(stoi(operations[i]));
            }
        }
        if(st.empty()) return 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};