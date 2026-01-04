class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {
            int cnt = 0;
            int sum = 0;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    cnt++;
                    sum += i;

                    if (i != x / i) {
                        cnt++;
                        sum += x / i;
                    }

                    if (cnt > 4) break;
                }
            }

            if (cnt == 4) {
                totalSum += sum;
            }
        }
        return totalSum;
    }
};
