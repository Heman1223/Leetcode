class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int row,int col,int color,int old_color){
        if(i < 0 || j < 0 || i >= row || j >= col || image[i][j] != old_color || image[i][j] == color){
            return;
        }
        image[i][j] = color;
        dfs(image,i + 1, j , row, col ,color , old_color);
        dfs(image,i - 1, j , row, col ,color , old_color);
        dfs(image,i , j + 1 , row, col ,color , old_color);
        dfs(image,i , j - 1 , row, col ,color , old_color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();                      
        int col = image[0].size();
        int old_color = image[sr][sc];

        dfs(image,sr,sc,row,col,color,old_color);
        return image;
    }
};