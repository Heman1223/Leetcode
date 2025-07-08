class Solution {
public:
    bool possible(vector<int>& nums,int maxsum,int k){
        int count = 1;
        int currsum = 0;
        for(int num : nums){
            if(currsum + num <= maxsum){
                currsum += num;
            }else{
                count++;
                currsum = num;
            }
            if(count > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(possible(nums,mid,k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};