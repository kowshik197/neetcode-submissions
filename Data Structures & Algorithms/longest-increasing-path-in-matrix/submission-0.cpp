class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int f(int r, int c, vector<vector<int>>& matrix) {

        if(dp[r][c] != -1)
            return dp[r][c];

        int best = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               matrix[nr][nc] > matrix[r][c]) {

                best = max(best, 1 + f(nr, nc, matrix));
            }
        }

        return dp[r][c] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                ans = max(ans, f(r, c, matrix));
            }
        }

        return ans;
    }
};