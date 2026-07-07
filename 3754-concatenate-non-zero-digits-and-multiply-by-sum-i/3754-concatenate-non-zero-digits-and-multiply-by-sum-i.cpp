class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        string num = to_string(n);
        for(char c : num){
            if(c == '0') continue;
            sum += (c - '0');
            x = x * 10 + (c - '0');
        }
        return x * sum;
    }
};