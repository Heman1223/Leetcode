class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check;
        for(int num : nums) {
            if(check.count(num)) {
                return true; // duplicate found
            }
            check.insert(num);
        }
        return false; // no duplicates
    }
};