class Solution {
public:
    bool is_before(int idx, vector<vector<int>>& matrix, int target) {

        int cols = matrix[0].size();

        int row = idx / cols;
        int col = idx % cols;

        return matrix[row][col] < target;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = rows * cols - 1;

        // Entire range is "after"
        if (!is_before(l, matrix, target)) {
            int row = l / cols;
            int col = l % cols;
            return matrix[row][col] == target;
        }

        // Entire range is "before"
        if (is_before(r, matrix, target)) {
            return false;
        }

        while (r - l > 1) {

            int mid = l + (r - l) / 2;

            if (is_before(mid, matrix, target))
                l = mid;
            else
                r = mid;
        }

        int row = r / cols;
        int col = r % cols;

        return matrix[row][col] == target;
    }
};