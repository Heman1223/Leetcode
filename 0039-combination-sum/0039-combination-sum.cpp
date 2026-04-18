class Solution {
public:
    void func(int i,vector<int>& candidates,vector<vector<int>> &ans, vector<int> &temp,int target){
        if(i == candidates.size() || target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[i]);
        func(i,candidates,ans,temp,target - candidates[i] );
        temp.pop_back();
        func(i + 1,candidates,ans,temp,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,candidates,ans,temp,target);
        return ans;
    }
};