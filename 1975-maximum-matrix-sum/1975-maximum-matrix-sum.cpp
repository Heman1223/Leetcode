class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long cnt = 0;
        long smallest = LONG_MAX;
        long sum = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j < m;j++){
                // To count number of negatives
                if(matrix[i][j] < 0){
                    cnt++;
                }
                long val = abs(matrix[i][j]);
                smallest = min(smallest, val);
                sum += val;
            }
        }
        if(cnt % 2 == 0) return sum;
        return sum - (2 * smallest);
    }
};