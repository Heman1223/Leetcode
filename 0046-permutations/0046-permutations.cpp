class Solution {
public:
    void func(int idx,vector<vector<int>> &ans,vector<int>& nums){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx ; i < nums.size();i++){
            swap(nums[i],nums[idx]);
            func(idx + 1,ans,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,ans,nums);
        return ans;
    }
};