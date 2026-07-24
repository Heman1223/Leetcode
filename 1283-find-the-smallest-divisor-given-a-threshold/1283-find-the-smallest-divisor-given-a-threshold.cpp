class Solution {
public:
    bool possible(int mid,vector<int>& nums,int threshold){
        int sum = 0;
        for(int num : nums){
            int temp = (num + mid - 1)/mid;
            sum += temp;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;

        while(s <= e){
            int mid = (s + e)/2;
            if(possible(mid,nums,threshold)){
                ans = min(ans,mid);
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};