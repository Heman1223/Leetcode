class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]){
            return 0;
        }
        int x1 = source[0];
        int x2 = target[0];
        int y1 = source[1];
        int y2 = target[1];

        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        if(x == y || x1 == x2 || y1 == y2){
            return 1;
        }
        return 2;
        
    }
};