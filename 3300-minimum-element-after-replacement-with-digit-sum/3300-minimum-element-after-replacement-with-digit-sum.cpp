class Solution {
public:
    int sum(int num){
        int s = 0;
        string str = to_string(num);
        for(char i : str){
            s = s + (i - '0');
        }
        return s;
    }
    int minElement(vector<int>& nums) {
        int minsum = INT_MAX;

        for(int i : nums){
            int currsum = sum(i);
            minsum = min(currsum,minsum);
        }
        return minsum;
    }
};