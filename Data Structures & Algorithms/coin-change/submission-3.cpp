class Solution {
public:

    vector<int> dp;
    vector<int> coins;

    int f(int amount) {

        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return INT_MAX;
        }

        if(dp[amount] != -1) {
            return dp[amount];
        }

        int ans = INT_MAX;

        for(int coin : coins) {

            int res = f(amount - coin);

            if(res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        this->coins = coins;

        dp.assign(amount + 1, -1);

        int ans = f(amount);

        return ans == INT_MAX ? -1 : ans;
    }
};

// class Solution {
// public:

//     vector<vector<int>> dp;
//     vector<int> coins;
//     int n;

//     int f(int i, int amount) {

//         if(amount == 0) {
//             return 0;
//         }

//         if(i == n) {
//             return INT_MAX;
//         }

//         if(dp[i][amount] != -1) {
//             return dp[i][amount];
//         }

//         int take = INT_MAX;

//         if(amount >= coins[i]) {

//             int res = f(i, amount - coins[i]);

//             if(res != INT_MAX) {
//                 take = 1 + res;
//             }
//         }

//         int skip = f(i + 1, amount);

//         return dp[i][amount] = min(take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {

//         this->coins = coins;
//         n = coins.size();

//         dp.assign(n, vector<int>(amount + 1, -1));

//         int ans = f(0, amount);

//         return ans == INT_MAX ? -1 : ans;
//     }
// };