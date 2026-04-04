class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        set<int> st;
        long long ans = 0;
        long long sum = 0;
        int j = 0;
        for(int i = 0;i < nums.size();i++){
            while(st.count(nums[i])){
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }
            st.insert(nums[i]);
            sum += nums[i];
            if(i - j + 1 == k){
                ans = max(ans,sum);
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }
        }
        return ans;
    }
};