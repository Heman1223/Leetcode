class Solution {
private:
    void function(int start,vector<int>& candidates,int target,vector<int> comb,vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        for(int i = start;i < candidates.size();i++){
            if(candidates[i] <= target){
                comb.push_back(candidates[i]);
                function(i,candidates,target - candidates[i],comb,ans);
                comb.pop_back();
            }

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        function(0,candidates,target,comb,ans);
        return ans;
    }
};