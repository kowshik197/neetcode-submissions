// class Solution {
// public:
//     vector<vector<int>> ans;

//     void backtrack(int index, vector<int>& nums, vector<int>& path) {

//         if (index == nums.size()) {
//             ans.push_back(path);
//             return;
//         }

//         // Decision 1: Include nums[index]
//         path.push_back(nums[index]);
//         backtrack(index + 1, nums, path);
//         path.pop_back();

//         // Decision 2: Exclude nums[index]
//         while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
//             index++;
//         }

//         backtrack(index + 1, nums, path);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         vector<int> path;
//         backtrack(0, nums, path);

//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void backtrack(int idx, vector<int>& nums) {
        ans.push_back(curr);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])   // Here first occurence is valid... so we make i>idx
                continue; // Skip duplicate choices

            curr.push_back(nums[i]);
            backtrack(i + 1, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};