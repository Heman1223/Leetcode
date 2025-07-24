class Solution {

private:
    void solve(vector<vector<int>> matrix,vector<vector<int>>& ans,int col,int row,int cols,int rows){
        if(col >= cols || row >= rows){
            return;
        }
        if(matrix[row][col] == 0){
            for(int i = 0;i<cols;i++){
                    ans[row][i] = 0;
            }
            for(int j=0;j<rows;j++){
                    ans[j][col] = 0;
                }
        }
        solve(matrix,ans,col + 1,row,cols,rows);
        solve(matrix,ans,col,row + 1,cols,rows);
        
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> ans = matrix;
        solve(matrix,ans,0,0,cols,rows);
        matrix = ans;
    }
};