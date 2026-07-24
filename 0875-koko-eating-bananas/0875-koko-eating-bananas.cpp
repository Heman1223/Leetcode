class Solution {
public:
    bool possible(vector<int>& piles,int mid,int h){
        long long hours = 0;
        for(int pile : piles){
            if(pile < mid){
                hours++;
            }else{
                hours += (pile + mid - 1)/mid;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        
        while(s <= e){
            int mid = (s + e)/2;
            if(possible(piles,mid,h)){
                ans = min(mid,ans);
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};