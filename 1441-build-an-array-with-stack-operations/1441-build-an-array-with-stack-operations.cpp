class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int idx = 0;  // index for target
        
        for (int num = 1; num <= n && idx < target.size(); num++) {
            operations.push_back("Push");
            
            if (num == target[idx]) {
                idx++;  // move to next target element
            } else {
                operations.push_back("Pop");
            }
        }
        
        return operations;
    }
};