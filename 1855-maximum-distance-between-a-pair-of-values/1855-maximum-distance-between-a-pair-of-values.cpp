class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int ans = -1e9;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                ans = max(ans,abs(i - j));
                j++;
            }else{
                j++;
                i++;
            }
        }
        return ans == -1e9 ? 0 : ans;
    }
};