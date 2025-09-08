class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;
        if(b%10 == 0){
            return {a+1,b-1};
        }
        return {a,b};

    }
};