class Solution {
public:
    void addSolution(vector<vector<string>> &ans,vector<vector<string>> &board,int n){
        vector<string> temp;
        for(int i = 0;i<n;i++){
            string row = "";
            for(int j = 0;j < n;j++){
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row,int col,vector<vector<string>> &board,int n){
        //Row,Diagonal Left-Up,Diagonal Left-Down
        int x = row;
        int y = col;

        //ROW
        while(y >= 0){
            if(board[x][y] == "Q"){
                return false;
            }
            y--;
        }
        x = row,y = col;

        //Diagonal Left-Up
        while(x >= 0 && y >= 0){
            if(board[x][y] == "Q"){
                return false;
            }
            x--;
            y--;
        }

        x = row,y = col;
        while(x < n && y >=0){
            if(board[x][y] == "Q"){
                return false;
            }
            x++;
            y--;
        }
        return true;

    }
    void solve(vector<vector<string>> &ans,vector<vector<string>> &board,int col,int n){
        if(col == n){
            addSolution(ans,board,n);
            return;
        }
        for(int row = 0;row < n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = "Q";
                solve(ans,board,col + 1,n);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n,vector<string>(n,"."));
        vector<vector<string>> ans;
        solve(ans,board,0,n);
        return ans;
    }
};