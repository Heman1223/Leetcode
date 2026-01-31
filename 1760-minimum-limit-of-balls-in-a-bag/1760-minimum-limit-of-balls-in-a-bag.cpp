class Solution {
public:
    bool possible(vector<int>& nums,int maxOperations,int mid){
        long long poss = 0;
        for(int i : nums){
            poss += (i - 1)/mid;
        }
        return poss <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int end = INT_MIN;
        for(int i : nums){
            end = max(end,i);
        }
        int start = 1;
        int ans = 0;
        while(start <= end){
            int mid = (start + end)/2;
            if(possible(nums,maxOperations,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};