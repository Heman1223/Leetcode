class Solution {
public:
    void dfs(int i,int j,int row,int col,vector<vector<int>>& heights,vector<vector<int>> &mat,int prevHeight ){
        if(i < 0 || j < 0 || i >= row || j >= col || mat[i][j] == 1 || heights[i][j] < prevHeight){
            return;
        }
        mat[i][j] = 1;
        dfs(i - 1 , j, row, col, heights, mat, heights[i][j]);
        dfs(i + 1 , j , row, col, heights, mat, heights[i][j]);
        dfs(i , j + 1, row, col, heights, mat, heights[i][j]);
        dfs(i , j - 1, row, col, heights, mat, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> atlantic(m,vector<int> (n,0));
        vector<vector<int>> pacific(m,vector<int> (n,0));

        for(int i = 0;i < m;i++){
            dfs(i,0,m,n,heights,pacific,0); // Pacific Left
            dfs(i,n - 1,m,n,heights,atlantic,0); // Atlantic Right
        }
        for(int i = 0;i < n;i++){
            dfs(0,i,m,n,heights,pacific,0); // Pacific Top
            dfs(m - 1,i,m,n,heights,atlantic,0); // Atlantic Bottom
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(atlantic[i][j] == 1 && pacific[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};