class Solution {
public:

    void function(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i]) != temp.end()){
                continue;
            }
            temp.push_back(nums[i]);
            function(nums,res,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        function(nums,res,temp);
        return res;
    }
};