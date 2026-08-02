class Solution {
public:

 vector<int> dp;

    int f(int i, int n,vector<int>& cost) {

    if (i >= n - 2) {
      return cost[i];
    }

        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] =cost[i]+min( f(i + 2, n,cost) ,f(i + 1, n,cost));
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n , -1);

        return min(f(0, n,cost),f(1, n,cost));
    }
};