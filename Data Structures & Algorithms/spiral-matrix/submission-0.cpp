class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        vector<vector<int>> dir = {
            {0, 1},   // Right
            {1, 0},   // Down
            {0,-1},   // Left
            {-1,0}    // Up
        };

        int r = 0, c = 0;
        int d = 0;   // Start moving Right

        for (int k = 0; k < m * n; k++) {

            ans.push_back(matrix[r][c]);
            vis[r][c] = true;

            int nr = r + dir[d][0];
            int nc = c + dir[d][1];

            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n ||
                vis[nr][nc]) {

                d = (d + 1) % 4;

                nr = r + dir[d][0];
                nc = c + dir[d][1];
            }

            r = nr;
            c = nc;
        }

        return ans;
    }
};