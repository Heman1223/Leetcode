class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].size();

        for(auto& it : queries){
            for(auto& it2 : dictionary){
                int diff = 0;
                for(int i = 0;i < n;i++){
                    if(it[i] != it2[i]){
                        diff++;
                    }
                    if(diff > 2) break;
                }
                if(diff <= 2){
                    ans.push_back(it);
                    break;
                }
                
            }
        }
        return ans;
    }
};