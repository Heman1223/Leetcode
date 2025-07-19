class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<vector<int>> q;
        int zeroes = 0;
        for(int i = 0 ;i<row;i++){
            for(int j = 0;j<col;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    zeroes++;
                }else{
                    mat[i][j] = -1;
                }
            }
        }
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                vector<int> node = q.front();
                q.pop();
                for(int j=0;j < 4;j++){
                    int x = node[0] + dx[j];
                    int y = node[1] + dy[j];
                    if (x >= 0 && y >= 0 && x < row && y < col && mat[x][y] == -1) {
                        mat[x][y] = mat[node[0]][node[1]] + 1;
                        q.push({x, y});
                    }
                    
                }
            }
        }
        return mat;
    }
};