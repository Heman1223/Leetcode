class Solution {
public:
    void func(int i,vector<int> &temp,vector<vector<int>> &ans,vector<int> &nums,int target,int k){
        if(target == 0 && temp.size() == k){
            //st.insert(temp);
            ans.push_back(temp);
            return;
        }
        if(i == nums.size() || target < 0 || temp.size() > k ){
            return;
        }
        
        temp.push_back(nums[i]);
        func(i + 1,temp,ans,nums,target - nums[i],k);
        temp.pop_back();
        func(i + 1,temp,ans,nums,target,k);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        //unordered_set<vector<int>> st;
        func(0,temp,ans,nums,n,k);
        return ans;
    }
};