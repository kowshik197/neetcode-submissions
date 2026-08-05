class Solution {
public:

    int n;
    vector<vector<int>> dp;
    vector<int> prices;

    int f(int i, int bought) {

        if(i >= n)
            return 0;

        if(dp[i][bought] != -1)
            return dp[i][bought];

        if(bought == 0) {

            return dp[i][0] = max(
                -prices[i] + f(i+1,1),
                f(i+1,0)
            );
        }

        return dp[i][1] = max(
            prices[i] + f(i+2,0),
            f(i+1,1)
        );
    }

    int maxProfit(vector<int>& prices) {

        this->prices = prices;
        n = prices.size();

        dp.assign(n, vector<int>(2,-1));

        return f(0,0);
    }
};