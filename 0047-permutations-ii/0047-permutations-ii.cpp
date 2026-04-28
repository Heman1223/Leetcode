class Solution {
public:
     void func(int idx,vector<vector<int>> &ans,vector<int>& nums){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i = idx ; i < nums.size();i++){
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i],nums[idx]);
            
            func(idx + 1,ans,nums);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0,ans,nums);
        return ans;
    }
};