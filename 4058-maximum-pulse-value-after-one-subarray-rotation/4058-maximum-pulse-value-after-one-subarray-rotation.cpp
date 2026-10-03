class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long org = 0;
        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                org += nums[i];
            }else{
                org -= nums[i];
            }
        }
        long long odd = LLONG_MIN;
        long long even = 0;
        long long best = 0;

        for(int i = 0;i < nums.size();i++){
            long long gain;
            if(i%2 == 0){
                gain = -2LL * nums[i];
            }else{
                gain = 2LL * nums[i];
            }
            long long oldo = odd;
            long long olde = even;
            odd = max(gain,olde + gain);
            if(oldo != LLONG_MIN)
                even = oldo + gain;
            best = max(best,even);
        }
        return org + best;
        
    }
};