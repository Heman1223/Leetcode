class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        vector<int> ans;
        if(nums1.size() > nums2.size()){
            for(int num : nums1){
                map[num] = true;
            }
            for(int num : nums2){
                if(map[num] == true){
                    map[num] = false;
                    ans.push_back(num);
                }
            }
        }else{
            for(int num : nums2){
                map[num] = true;
            }
            for(int num : nums1){
                if(map[num] == true){
                    map[num] = false;
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};