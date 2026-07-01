class Solution {
public:
    bool safe(vector<string>&board,int r,int c){
        int n = board.size();
        for(int i = r-1; i >= 0;i--){
            if(board[i][c] == 'Q') return false;
        }
        for(int i = r - 1,j = c+1;i >= 0 && j < n;i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = r - 1,j = c-1;i >= 0 && j >=0 ;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int r,vector<string> board,vector<vector<string>>& ans,int n){
        if(r == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i < n;i++){
            if(safe(board,r,i)){
                board[r][i] = 'Q';
                solve(r + 1,board,ans,n);
                board[r][i] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,board,ans,n);
        return ans;

    }
};