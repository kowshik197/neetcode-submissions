class Solution {
public:
    int n;
    int target;
    vector<int> nums;
    unordered_map<string, int> dp;

    int f(int i, int sum) {

        // Used all numbers
        if(i == n) {
            return sum == target;
        }

        string key = to_string(i) + "," + to_string(sum);

        if(dp.find(key) != dp.end()) {
            return dp[key];
        }

        // Two choices:
        // 1. Put +
        // 2. Put -
        int add = f(i + 1, sum + nums[i]);
        int sub = f(i + 1, sum - nums[i]);

        return dp[key] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        this->nums = nums;
        this->target = target;
        n = nums.size();

        return f(0, 0);
    }
};