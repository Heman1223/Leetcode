class Solution {
public:
    bool func(int i,vector<int>& arr,int n){
        if(i < 0 || i >= n){
            return false;
        }
        if(arr[i] == 0) return true;
        if(arr[i] < 0) return false;
        int step = arr[i];
        arr[i] = -arr[i];
        return (func(i + step,arr,n) || func(i - step,arr,n));
    } 
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        return func(start,arr,n);
    }
};