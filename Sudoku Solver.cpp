class Solution {
public:
   bool isValid(int r, int c, vector<vector<char>>& board, char ch){
          for(int i=0;i<9;i++){
            if(board[r][i] == ch) return false;

            if(board[i][c] == ch) return false;

            int boxRow = 3 * (r / 3) + i / 3;
            int boxCol = 3 * (c / 3) + i % 3;
            if(board[boxRow][boxCol] == ch) return false;
          }
          return true;
   }

    bool f(vector<vector<char>>& board){
        for(int row = 0;row < 9;row++){
            for(int col = 0;col < 9;col++){
                if(board[row][col] == '.') {
                  for(char ch = '1';ch <='9';ch++){
                    if(isValid(row,col,board,ch)){
                        board[row][col] = ch;
                        if(f(board)) return true;
                        else board[row][col] = '.';
                    }
                  }
                  return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};
