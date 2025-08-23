class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board,int n){
        int r = row;
        int c = col;
        // check upper-left diagonal (↖)
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r--;
            c--;
        }

        // check left row (←)
        c = col;
        r = row;
        while(c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            c--;
        }

        // check lower-left diagonal (↙)
        c = col;
        r = row;
        while(r<n && c>=0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r++;
            c--;
        }
        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<string>& board, int n){
        // base case 
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(0, ans, board, n);
        return ans;

    }
};

// optmimization -> using hashing
// TC: O(n!)
// SC: O(n²)
class Solution {
public:
    void solve(int col, vector<vector<string>> &ans, vector<string>& board, int n,
    vector<int> &leftRow, vector<int>&upperDiag, vector<int>&lowerDiag){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
                if (leftRow[row] == 0 && upperDiag[n - 1 + col - row] == 0 && lowerDiag[row + col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiag[n - 1 + col - row] = 1;
                lowerDiag[row+col] = 1;

                solve(col+1, ans, board, n, leftRow, upperDiag, lowerDiag);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiag[n - 1 + col - row] = 0;
                lowerDiag[row+col] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int>leftRow(n, 0);
        vector<int> upperDiag(2*n-1, 0);
        vector<int> lowerDiag(2*n-1, 0);
        solve(0, ans, board, n, leftRow, upperDiag, lowerDiag);
        return ans;

    }
};
