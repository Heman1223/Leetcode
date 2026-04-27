class Solution {
public:
    void func(int i, vector<int>& temp,vector<vector<int>>& ans,vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        func(i + 1,temp,ans,nums);
        temp.pop_back();
        func(i + 1,temp,ans,nums);
       // temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(0,temp,ans,nums);
        return ans;
    }
};