class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int minr = 0;
        int maxr = 0;
        for(char c : moves){
            if(c == 'L'){
                minr--;
                maxr--;
            }else if(c == 'R'){
                minr++;
                maxr++;
            }else{
                minr--;
                maxr++;
            }
        }
        return max(abs(minr),maxr);
    }
};