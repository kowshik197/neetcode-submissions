class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for(int x : nums) {

            auto it = lower_bound(tails.begin(), tails.end(), x);

            if(it == tails.end()) {
                tails.push_back(x);
            }
            else {
                *it = x;
            }
        }

        return tails.size();
    }
};
// //My DP Approach
// class Solution {
// public:

//     vector<int> dp;

//     int f(int i, vector<int>& nums) {

//         if(dp[i] != -1)
//             return dp[i];

//         int ans = 1;

//         for(int j = i + 1; j < nums.size(); j++) {

//             if(nums[i] < nums[j]) {
//                 ans = max(ans, 1 + f(j, nums));
//             }
//         }

//         return dp[i] = ans;
//     }

//     int lengthOfLIS(vector<int>& nums) {

//         int n = nums.size();

//         dp.resize(n, -1);

//         int ans = 0;

//         for(int i = 0; i < n; i++) {
//             ans = max(ans, f(i, nums));
//         }

//         return ans;
//     }
// };