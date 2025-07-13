class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         for (int i = 0; i < 9; i++) {
            vector<bool> row(9, false);
            vector<bool> col(9, false);
            vector<bool> box(9, false);

            for (int j = 0; j < 9; j++) {
               
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (row[num]) return false;
                    row[num] = true;
                }

               
                if (board[j][i] != '.') {
                    int num = board[j][i] - '1';
                    if (col[num]) return false;
                    col[num] = true;
                }

               
                int rowIndex = 3 * (i / 3) + (j / 3);
                int colIndex = 3 * (i % 3) + (j % 3);
                if (board[rowIndex][colIndex] != '.') {
                    int num = board[rowIndex][colIndex] - '1';
                    if (box[num]) return false;
                    box[num] = true;
                }
            }
        }
        return true;
    }
};
