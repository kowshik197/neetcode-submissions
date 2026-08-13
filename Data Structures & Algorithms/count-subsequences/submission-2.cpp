class Solution {
   public:
    string s = "", t = "";
    vector<vector<int>> dp;
    int f(int i, int j) {
        if (j == t.size()) {
            return 1;  // We reached the end of string , hence string formed
        }

        if (i == s.size()) {
            return 0;  // No more characters left to get string t
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            dp[i][j] = f(i + 1, j + 1) + f(i + 1, j);  // Take choice + skip choice
        } else {
            dp[i][j] = f(i + 1, j);  // Skip choice
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        int m = s.size();
        int n = t.size();
        this->s = s;
        this->t = t;
        dp.assign(m, vector<int>(n, -1));
        return f(0, 0);
    }
};