class Solution {
public:
    void dfs(vector<vector<int>> &heights, int i, int j, int row, int col, vector<vector<bool>> &mat, int prevHeight){
        if(i < 0 || j < 0 || i >= row || j >= col || mat[i][j] == true || heights[i][j] < prevHeight){
            return;
        }
        mat[i][j] = true;
        dfs(heights, i, j + 1, row, col, mat, heights[i][j]);
        dfs(heights, i, j - 1, row, col, mat, heights[i][j]);
        dfs(heights, i + 1, j, row, col, mat, heights[i][j]);
        dfs(heights, i - 1, j, row, col, mat, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, row, col, pacific, 0);         // Pacific (left)
            dfs(heights, i, col - 1, row, col, atlantic, 0);  // Atlantic (right)
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, row, col, pacific, 0);         // Pacific (top)
            dfs(heights, row - 1, j, row, col, atlantic, 0);  // Atlantic (bottom)
        }
        vector<vector<int>> ans;
        
        for(int i=0;i<row;i++){
            for(int j = 0;j < col;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};