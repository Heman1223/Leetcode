class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        int mindiff = INT_MAX;
        sort(arr.begin(),arr.end());
        int l = 0;
        int r = l + 1;
        while(r < n){
            mindiff = min(mindiff, arr[r] - arr[l]);
            l++;
            r++;
        }
        l = 0;
        r = l + 1;
        while(r < n){
            if(arr[r] - arr[l] == mindiff){
                ans.push_back({arr[l] , arr[r]});
            }
            l++;
            r++;
        }
        return ans;
    }
};