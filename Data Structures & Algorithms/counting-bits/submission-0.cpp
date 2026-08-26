class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n >> 1) + (n & 1);
    }

    vector<int> countBits(int n) {
        dp.resize(n + 1, -1);

        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            ans.push_back(solve(i));
        }

        return ans;
    }
};