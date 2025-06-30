class Solution {
private:
    bool isPossible(vector<int> piles,int speed,int h){
        long long hours = 0;
        for(int pile : piles){
            hours += (pile + speed - 1)/speed;
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid = (low + high)/2;
            if(isPossible(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};