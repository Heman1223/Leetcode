class Solution {
public:
    void dfs(int r,int c,vector<vector<char>> &board,int n,int m){
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O'){
            return;
        }
        board[r][c] = 'S';
        dfs(r + 1, c ,board, n ,m);
        dfs(r - 1, c ,board, n ,m);
        dfs(r , c + 1 ,board, n ,m);
        dfs(r , c - 1 ,board, n ,m);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0;i < n;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board,n,m);
            }
            if(board[i][m - 1] == 'O'){
                dfs(i,m - 1,board,n,m);
            }
        }
        for(int i = 0;i < m;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board,n,m);
            }
            if(board[n - 1][i] == 'O'){
                dfs(n - 1,i,board,n,m);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};