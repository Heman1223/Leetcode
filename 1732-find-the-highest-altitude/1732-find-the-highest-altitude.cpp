class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curralt = 0;
        for(int i : gain){
            curralt += i;
            ans = max(curralt,ans);
        }
        return ans;
    }
};