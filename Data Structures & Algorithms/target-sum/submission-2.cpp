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




// // Optimisedddd
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {

//         int total = 0;

//         for(int x : nums) {
//             total += x;
//         }

//         // Impossible cases
//         if(abs(target) > total)
//             return 0;

//         if((total + target) % 2 != 0)
//             return 0;

//         int subsetTarget = (total + target) / 2;

//         vector<int> dp(subsetTarget + 1, 0);

//         dp[0] = 1;

//         for(int num : nums) {

//             for(int s = subsetTarget; s >= num; s--) {

//                 dp[s] += dp[s - num];
//             }
//         }

//         return dp[subsetTarget];
//     }
// };