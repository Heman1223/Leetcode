class Solution {
public:
    void func(int idx,vector<int> &temp,vector<vector<int>>& ans,int target,vector<int>& candidates){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == candidates.size() || target < 0){
            return;
        }
        temp.push_back(candidates[idx]);
        func(idx,temp,ans,target - candidates[idx],candidates);
        temp.pop_back();
        func(idx + 1,temp,ans,target,candidates);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,temp,ans,target,candidates);
        return ans;
    }
};