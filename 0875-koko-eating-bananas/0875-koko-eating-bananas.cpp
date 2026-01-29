class Solution {
public:
    bool possible(vector<int>& piles,int h,int speed){
        long long hour = 0;
        for(int pile : piles){
            if(speed >= pile){
                hour++;
            }else{
                hour += (pile + speed - 1) / speed;
            }
        }
        if(hour <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int end = 0;
        for(int pile : piles){
            end = max(pile,end);
        }
        int start = 1;
        int speed = end;
        while(start <= end){
            int mid = (start + end)/2;
            if(possible(piles,h,mid)){
                speed = min(mid,speed);
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return speed;
    }
};