class Solution {
public:
    int rows, cols;

    bool backtrack(int r, int c, int index,
                   vector<vector<char>>& board,
                   string& word) {

        // Entire word matched
        if (index == word.size())
            return true;

        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;

        // Character mismatch
        if (board[r][c] != word[index])
            return false;

        // Already visited
        if (board[r][c] == '#')
            return false;

        // Mark visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found =
            backtrack(r + 1, c, index + 1, board, word) ||
            backtrack(r - 1, c, index + 1, board, word) ||
            backtrack(r, c + 1, index + 1, board, word) ||
            backtrack(r, c - 1, index + 1, board, word);

        // Undo (Backtrack)
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (backtrack(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};