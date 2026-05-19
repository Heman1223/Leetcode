class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m){
            if(nums1[i] == nums2[j]) return nums1[i];
            if(nums1[i] > nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        while(i < n){
            if(nums1[i] == nums2[j - 1]) return nums1[i];
            i++;
        }
        while(j < m){
            if(nums1[i - 1] == nums2[j]) return nums1[i - 1];
            j++;
        }
        return -1;
    }
};