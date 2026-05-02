class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> ans;
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        int leftmax = nums[0];
        for(int i = 1;i < n;i++){
            left[i] = leftmax;
            if(nums[i] > leftmax){
                leftmax = nums[i];
            }
        }
        int rightmax = nums[n - 1];
        for(int i = n - 2;i >= 0;i--){
            right[i] = rightmax;
            if(nums[i] > rightmax){
                rightmax = nums[i];
            }
        }
        
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size() - 1;i++){
            if(nums[i] > left[i] || nums[i] > right[i]){
                ans.push_back(nums[i]);
            }
        } 
        ans.push_back(nums[n - 1]);
        return ans;
    }
};