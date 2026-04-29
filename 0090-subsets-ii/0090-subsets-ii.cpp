class Solution {
public:
    void func(int i,vector<int> &temp,vector<vector<int>> &ans,vector<int> &nums){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(i + 1,temp,ans,nums);
        temp.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        func(i + 1,temp,ans,nums);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        func(0,temp,ans,nums);
        return ans;
    }
};