class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums){
            vector<int> temp;
            while(i > 0){
                int rem = i%10;
                i /= 10;
                temp.push_back(rem);
            }
            for(int j = temp.size() - 1;j >= 0;j--){
                ans.push_back(temp[j]);
            }
        }
        return ans;
    }
};