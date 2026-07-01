class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,char k,int n){
        for(int i = 0;i < n;i++){
            if(board[i][col] == k) return false;
            if(board[row][i] == k) return false;
        }
        int nr = (row/3) * 3;
        int nc = (col/3) * 3;

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[nr + i][nc + j] == k) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> & board){
        int n = board.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == '.'){
                    for(char k = '1';k <= '9';k++) {
                        if(check(board,i,j,k,n)){
                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};