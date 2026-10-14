class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        bool ok=true;
                        for(int k=0;k<9;k++)
                            if(board[i][k]==c||board[k][j]==c||
                            board[3*(i/3)+k/3][3*(j/3)+k%3]==c)
                                ok=false;
                        if(ok){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
