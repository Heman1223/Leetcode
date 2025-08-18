class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int num = original ;
        while(find(nums.begin(),nums.end(),num) != nums.end()){
            num *= 2;
        }
        return num;
    }
};