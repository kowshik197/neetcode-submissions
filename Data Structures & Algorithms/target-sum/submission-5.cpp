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

//using 2d vector...
// #include <vector>
// #include <numeric>
// #include <cmath>
// #include <cstdlib>

// class Solution {
// public:
//     int n;
//     int target;
//     int total;
//     std::vector<int> nums;
//     std::vector<std::vector<int>> dp;

//     int f(int i, int sum) {
//         // Base case: processed all numbers
//         if (i == n) {
//             return sum == target;
//         }

//         // Offset the sum to handle negative values safely in vector indices
//         int shiftedSum = sum + total;

//         // Return memoized result if available
//         if (dp[i][shiftedSum] != -1) {
//             return dp[i][shiftedSum];
//         }

//         // Explore choices: + and -
//         int add = f(i + 1, sum + nums[i]);
//         int sub = f(i + 1, sum - nums[i]);

//         return dp[i][shiftedSum] = add + sub;
//     }

//     int findTargetSumWays(std::vector<int>& nums, int target) {
//         this->nums = nums;
//         this->target = target;
//         this->n = nums.size();
        
//         this->total = 0;
//         for (int x : nums) {
//             total += x;
//         }

//         // If target is out of achievable bounds, return 0 early
//         if (std::abs(target) > total) return 0;

//         // Initialize 2D DP table with size [n][2 * total + 1] filled with -1
//         dp.assign(n, std::vector<int>(2 * total + 1, -1));

//         return f(0, 0);
//     }
// };