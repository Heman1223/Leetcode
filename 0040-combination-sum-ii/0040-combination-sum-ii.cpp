class Solution {
public:
    void func(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int i, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == candidates.size() || target < 0) {
            return;
        }

        // Include current element
        temp.push_back(candidates[i]);
        func(candidates, temp, ans, i + 1, target - candidates[i]);
        temp.pop_back();

        // Skip duplicates
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++;

        // Exclude current element
        func(candidates, temp, ans, i + 1, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        func(candidates, temp, ans, 0, target);
        return ans;
    }
};