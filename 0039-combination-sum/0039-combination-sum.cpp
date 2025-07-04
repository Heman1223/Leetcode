class Solution {
private:
    void function(vector<int>& candidates,int target,int idx,int total,vector<int> comb,vector<vector<int>>& ans){
        if(total == target){
            ans.push_back(comb);
            return;
        }
        if(total > target || idx >= candidates.size()){
            return;
        }
        comb.push_back(candidates[idx]);
        function(candidates,target,idx,total + candidates[idx],comb,ans);
        comb.pop_back();
        function(candidates,target,idx + 1,total,comb,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> ans;
        function(candidates,target,0,0,comb,ans);
        return ans;
    }
};