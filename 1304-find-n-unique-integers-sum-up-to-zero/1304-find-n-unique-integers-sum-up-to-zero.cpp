class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1){
            return {0};
        }
        vector<int> ans;
        if(n%2 != 0){
            int m = (n - 1) / 2;
            for(int i = -m ; i <=m;i++){
                ans.push_back(i);
            }
        }else{
            int m = n/2;
            for(int i = -m;i<=m;i++){
                if(i == 0){
                    continue;
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};