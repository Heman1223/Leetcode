class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long largest = LLONG_MIN , seclarge = LLONG_MIN , thirdlarge = LLONG_MIN;
        for(int num : nums){
            if(num == largest || num == seclarge || num == thirdlarge) continue;
            if(num > largest){
                thirdlarge = seclarge;
                seclarge = largest;
                largest = num;
            }else if(num > seclarge){
                thirdlarge = seclarge;
                seclarge = num;
            }else if(num > thirdlarge){
                thirdlarge = num;
            }
        }
        if(thirdlarge == INT_MIN) return largest;
        return thirdlarge;
    }
};