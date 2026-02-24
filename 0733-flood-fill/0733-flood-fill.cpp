class Solution {
public:
    void dfs(vector<vector<int>> &image,int i,int j,int row,int col,int old_color,int color){
        if(i == row || j == col || i < 0 || j < 0 || image[i][j] != old_color || image[i][j] == color){
            return;
        }
        image[i][j] = color;
        dfs(image,i,j + 1,row,col,old_color,color);
        dfs(image,i + 1,j,row,col,old_color,color);
        dfs(image,i,j - 1,row,col,old_color,color);
        dfs(image,i - 1,j,row,col,old_color,color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        int old_color = image[sr][sc];
        dfs(image,sr,sc,row,col,old_color,color);
        return image;
    }
};