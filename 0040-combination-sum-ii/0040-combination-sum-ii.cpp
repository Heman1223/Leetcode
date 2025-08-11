class Solution {
public:
    void function(vector<int> &candidates,vector<vector<int>> &ans,vector<int> &comb,int target,int idx){
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        for(int i = idx ; i < candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            comb.push_back(candidates[i]);
            function(candidates,ans,comb,target - candidates[i],i + 1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        function(candidates,ans,comb,target,0);
        return ans;
    }
};