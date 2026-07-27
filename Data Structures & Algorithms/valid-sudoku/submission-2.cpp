#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Track seen numbers (1-9) for each row, column, and 3x3 box
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '0';
                int box = (r / 3) * 3 + (c / 3);

                // Check if the number has already appeared in the current row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[box][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};