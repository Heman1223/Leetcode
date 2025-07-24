class Solution {
public:
    bool isPossible(vector<int>& piles,int speed,int h){
        long long hour = 0;
        for(int pile : piles){
            hour += (pile + speed - 1)/speed;
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(isPossible(piles,mid,h)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};