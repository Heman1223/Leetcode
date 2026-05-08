class Solution {
public:
    void func(int i,vector<int> &temp,vector<vector<int>> &ans,vector<int> &candidates,int target){
        if(i == candidates.size() || target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        func(i,temp,ans,candidates,target - candidates[i]);
        temp.pop_back();
        func(i + 1,temp,ans,candidates,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        func(0,temp,ans,candidates,target);
        return ans;
    }
};