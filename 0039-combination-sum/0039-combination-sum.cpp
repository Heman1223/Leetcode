class Solution {
public:
    void function(vector<int>& candidates,vector<vector<int>> &ans,vector<int> comb,int target,int i){
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        if(target < 0 || i == candidates.size()){
            return;
        }
        comb.push_back(candidates[i]);
        function(candidates,ans,comb,target - candidates[i],i);
        comb.pop_back();
        function(candidates,ans,comb,target,i + 1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        function(candidates,ans,comb,target,0);
        return ans;
    }
};