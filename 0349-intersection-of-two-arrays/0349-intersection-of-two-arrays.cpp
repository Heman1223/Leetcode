class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> mp;
        vector<int> ans;
        for(int x : nums1){
            mp[x] = true;
        }

        for(int x : nums2){
            if(mp[x] == true){
                ans.push_back(x);
                mp[x] = false;
            }
        }
        return ans;
    }
};