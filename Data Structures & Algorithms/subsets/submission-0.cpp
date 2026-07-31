class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int index, vector<int>& nums, vector<int>& path) {

        // Base case
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }

        // Decision 1: Include nums[index]
        path.push_back(nums[index]);
        backtrack(index + 1, nums, path);
        path.pop_back();

        // Decision 2: Skip nums[index]
        backtrack(index + 1, nums, path);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(0, nums, path);
        return result;
    }
};