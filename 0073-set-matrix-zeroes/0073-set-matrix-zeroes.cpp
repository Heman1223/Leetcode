class Solution {

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(row,vector<int> (col));
        ans = matrix;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(matrix[i][j] == 0){
                    for(int k = 0;k < col;k++){
                        ans[i][k] = 0;
                    }
                    for(int k = 0;k < row;k++){
                        ans[k][j] = 0;
                    }
                }
            }
        }
        matrix = ans;
    }
};