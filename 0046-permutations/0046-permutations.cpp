class Solution {
public:

    void function(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp,int start){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(find(temp.begin(),temp.end(),nums[i]) != temp.end()){
                continue;
            }
            temp.push_back(nums[i]);
            function(nums,res,temp,i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        function(nums,res,temp,0);
        return res;
    }
};