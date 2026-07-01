class Solution {
public:
    bool solve(int i,int j, string& word,vector<vector<char>>& board,int idx,int n,int m){
        if(idx == word.length()) return true;
        if(!valid(i,j,n,m)) return false;
        if(board[i][j] != word[idx] || board[i][j] == '*') return false;
        char t = board[i][j];
        board[i][j] = '*';
        bool a = solve(i,j + 1,word, board,idx + 1,n,m);
        bool b = solve(i,j - 1,word, board,idx + 1,n,m);
        bool c = solve(i + 1,j ,word, board,idx + 1,n,m);
        bool d = solve(i - 1,j ,word, board,idx + 1,n,m);
        board[i][j] = t;

        return a || b || c || d;
    }
    bool valid(int i,int j,int n,int m){
        return i < n && j < m && i >= 0 && j >= 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j] == word[0]){
                   if(solve(i,j,word,board,0,n,m)) return true;
                }
            }
        }
        return false;
    }
};