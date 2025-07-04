class Solution {
void function(vector<int>& nums,int start,vector<int> temp,vector<vector<int>> &res){
    res.push_back(temp);
    for(int i=start;i<nums.size();i++){
        if(i > start && nums[i] == nums[i - 1]) continue;
        temp.push_back(nums[i]);
        function(nums,i + 1,temp,res);
        temp.pop_back();
     }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        //sort(nums.begin(),nums.end());
        function(nums,0,temp,res);
        return res;
    }
};