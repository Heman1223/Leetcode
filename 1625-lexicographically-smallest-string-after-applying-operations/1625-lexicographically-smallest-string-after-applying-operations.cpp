class Solution {
public:
    string add(string s, int a){
        for(int i = 0;i < s.size();i++){
            if(i%2 != 0){
                int num = ((s[i] - '0') + a)%10;
                s[i] = num + '0';
            }
        }
        return s;
    }
    string rotate(string a,int b){
        for(int j = 0;j < b;j++){
            for(int i = a.size() - 2;i >= 0;i--){
                swap(a[i],a[i + 1]);
            }
        }
        return a;
    }
    string findLexSmallestString(string s, int a, int b) {
        string ans = s;
        queue<string> q;
        q.push(s);
        set<string> st;
        st.insert(s);
        
        while(!q.empty()){
            string str = q.front();
            ans = min(str,ans);
            q.pop();
            string rot = rotate(str,b);
            if(!st.count(rot)){
                q.push(rot);
                st.insert(rot);
            }
            string ad = add(str,a);
            if(!st.count(ad)){
                q.push(ad);
                st.insert(ad);
            }
        }
        return ans;
    }
};