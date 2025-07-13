class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size() - 1;
        int i = 0;
        int j = cols;
        while(i < rows && j >=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};