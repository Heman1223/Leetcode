class Solution {
public:
    // DFS to mark safe cells connected to the border
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'S'; // mark as safe
        dfs(board, i + 1, j, row, col);
        dfs(board, i, j + 1, row, col);
        dfs(board, i - 1, j, row, col);
        dfs(board, i, j - 1, row, col);
        return;
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        // Run DFS on all border 'O' cells to mark safe regions
        for(int i = 0; i < row; i++) {
            if(board[i][0] == 'O') {
                dfs(board, i, 0, row, col);
            }
            if(board[i][col - 1] == 'O') {
                dfs(board, i, col - 1, row, col);
            }
        }
        for(int j = 0; j < col; j++) {
            if(board[0][j] == 'O') {
                dfs(board, 0, j, row, col);
            }
            if(board[row - 1][j] == 'O') {
                dfs(board, row - 1, j, row, col);
            }
        }

        // Flip the surrounded 'O' to 'X', and safe 'S' back to 'O'
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

};