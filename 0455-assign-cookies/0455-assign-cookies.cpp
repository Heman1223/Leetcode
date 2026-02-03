class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int i = g.size() - 1;
        int j = s.size() - 1;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i >= 0 && j >= 0){
            if(g[i] <= s[j]){
                count++;
                j--;
                i--;
            }else{
                i--;
            }
        }
        return count;
    }
};