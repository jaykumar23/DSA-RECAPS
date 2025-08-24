// TC: O(m * n * 4^L)
// SC: O(L) recursion depth
class Solution {
public:
    bool search(int i, int j, vector<vector<char>>& board, string word, int indx){
        // found entire word
        if(indx == word.length()) return true;
        
        int m = board.size();
        int n = board[0].size();

        // boundary / mismatch / visited checks
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='#' || board[i][j] != word[indx]) return false;

        char ch = board[i][j];
        // visited
        board[i][j] = '#';

        bool op1 = search(i+1, j, board, word, indx+1);
        bool op2 = search(i, j+1, board, word, indx+1);
        bool op3 = search(i-1, j, board, word, indx+1);
        bool op4 = search(i, j-1, board, word, indx+1);

        board[i][j] = ch; // backtrack

        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(search(i, j, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};
