class Solution {
public:
    void dfs(int i,int j,int n,int m,int old_color,int color,vector<vector<int>> &image){
        if( i < 0 || i >= n || j < 0 || j >= m || image[i][j] != old_color || image[i][j] == color){
            return;
        }
        image[i][j] = color;
        dfs(i + 1,j,n,m,old_color,color,image);
        dfs(i - 1,j,n,m,old_color,color,image);
        dfs(i,j + 1,n,m,old_color,color,image);
        dfs(i,j - 1,n,m,old_color,color,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int old_color = image[sr][sc];
        dfs(sr,sc,n,m,old_color,color,image);
        return image;
    }
};