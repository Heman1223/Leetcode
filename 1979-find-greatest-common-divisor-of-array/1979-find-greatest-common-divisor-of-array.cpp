class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m = 1e9;
        int mx = -1;
        for(auto it : nums){
            m = min(m,it);
            mx = max(mx,it);
        }
        return gcd(m,mx);
    }
};