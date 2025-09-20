class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() && nums[i] <= 0 ;i++){
            if(i == 0|| nums[i] != nums[i - 1]){
                twoSum2(nums,i,ans);
            }
        }
        return ans;
    }
    void twoSum2(vector<int>& nums,int i,vector<vector<int>> &ans){
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum < 0){
                left++;
            }else if(sum > 0){
                right--;
            }else{
                ans.push_back({nums[i],nums[left++],nums[right--]});
                while(left < right && nums[left] == nums[left-1]){
                    ++left;
                }
            }
        }
    }
};