class Solution {
public:
    string s, p;
    vector<vector<int>> dp;

    bool f(int i, int j) {

        // Pattern is completely used
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Does current pattern character match current string character?
        bool match = (i < s.size() &&
                      (p[j] == s[i] || p[j] == '.'));

        // If next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Choice 1: use x* zero times
            // Choice 2: if matched, consume one char and stay at j
            return dp[i][j] =
                f(i, j + 2) ||
                (match && f(i + 1, j));
        }

        // Normal character or '.'
        if (match) {
            return dp[i][j] = f(i + 1, j + 1);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        this->s = s;
        this->p = p;

        dp.assign(s.size() + 1,
                  vector<int>(p.size() + 1, -1));

        return f(0, 0);
    }
};