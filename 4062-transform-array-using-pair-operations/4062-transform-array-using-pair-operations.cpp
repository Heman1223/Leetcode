class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sumS = 0;
        long long sumT = 0;
        for(int x : source) sumS += x;
        for(int x : target) sumT += x;
        return sumS == sumT;
    }
};