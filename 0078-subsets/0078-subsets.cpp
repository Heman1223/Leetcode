class Solution {
public:
    void function(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp,int start){
        ans.push_back(temp);
        for(int i = start;i < nums.size();i++){
            temp.push_back(nums[i]);
            function(nums,ans,temp,i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        function(nums,ans,temp,0);
        return ans;
    }
};