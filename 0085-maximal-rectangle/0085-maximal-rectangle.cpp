class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> mat(r,vector<int>(c));
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                mat[i][j] = matrix[i][j] - '0';
            }
        }

        for(int i = 0;i < r;i++){
            for(int j = 1;j < c;j++){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j - 1];
                }
            }
        }
        int ans = 0;

        for(int j = 0; j < c;j++){
            for(int i = 0;i < r;i++){
                int width = mat[i][j];
                if(width == 0) continue;

                int currWidth = width;
                for(int k = i; k < r && mat[k][j] > 0;k++){
                    currWidth = min(currWidth,mat[k][j]);
                    int height = k - i + 1;
                    ans = max(ans , currWidth * height);
                }
                currWidth = width;
                for(int k = i; k >= 0 && mat[k][j] > 0;k--){
                    currWidth = min(currWidth,mat[k][j]);
                    int height = i - k + 1;
                    ans = max(ans, currWidth * height);
                }
            }
        }
        return ans;
    }
};