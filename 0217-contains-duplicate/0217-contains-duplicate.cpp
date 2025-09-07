class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> check;
        for(int i = 0;i<nums.size();i++){
            if(check[nums[i]] == true){
                return true;
            }
            check[nums[i]] = true;
        }
        return false;
    }
};