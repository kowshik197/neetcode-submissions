// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
        
//     }
// };


class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    int n;

    bool isValid(int row, int col) {

        // Check same column
        for(int r = 0; r < row; r++) {
            if(board[r][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for(int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if(board[r][c] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for(int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
            if(board[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(int row) {

        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {

            if(!isValid(row, col))
                continue;

            board[row][col] = 'Q';

            backtrack(row + 1);

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int N) {

        n = N;
        board = vector<string>(n, string(n, '.'));

        backtrack(0);

        return result;
    }
};