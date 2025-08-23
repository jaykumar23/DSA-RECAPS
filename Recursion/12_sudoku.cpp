class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board) {
        int boxRowStart = 3 * (row / 3);
        int boxColStart = 3 * (col / 3);

        for (int i = 0; i < 9; i++) {
            // check row
            if (board[row][i] == c)
                return false;

            // check column
            if (board[i][col] == c)
                return false;

            // check 3x3 box - // Check if the number exists in the 3x3 subgrid
            int boxRow = boxRowStart + i / 3;
            int boxCol = boxColStart + i % 3;
            if (board[boxRow][boxCol] == c)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, c, board)) {
                            board[i][j] = c;
                            if (solve(board)) {
                                return true; // solution
                            } else {
                                board[i][j] = '.'; // backtrack
                            }
                        }
                    }
                    return false;
                }
            }
        }
        // all chars filled already
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
