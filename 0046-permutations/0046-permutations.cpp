class Solution {
public:
    void func(vector<int> &temp,vector<vector<int>> &ans,vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            func(temp,ans,nums);
            temp.pop_back();


        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(temp,ans,nums);
        return ans;
    }
};