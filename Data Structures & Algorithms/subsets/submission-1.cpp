class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& nums, vector<int>& path) {

        // Every current path is a valid subset
        result.push_back(path);

        for(int i = start; i < nums.size(); i++) {

            // Choose
            path.push_back(nums[i]);

            // Move forward so we don't reuse the same index
            backtrack(i + 1, nums, path);

            // Undo
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> path;

        backtrack(0, nums, path);

        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> result;

//     void backtrack(int index, vector<int>& nums, vector<int>& path) {

//         // Base case
//         if (index == nums.size()) {
//             result.push_back(path);
//             return;
//         }

//         // Decision 1: Include nums[index]
//         path.push_back(nums[index]);
//         backtrack(index + 1, nums, path);
//         path.pop_back();

//         // Decision 2: Skip nums[index]
//         backtrack(index + 1, nums, path);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> path;
//         backtrack(0, nums, path);
//         return result;
//     }
// };