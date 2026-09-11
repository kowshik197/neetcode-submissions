class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i == 0 || nums[i] != nums[i - 1]){
                twoSumII(nums, i, res);
            }
        }

        return res;
    }

    void twoSumII(std::vector<int>& nums, int i, std::vector<vector<int>>& res){
        int start = i + 1;
        int end = nums.size() - 1;

        while(start < end){
            if(nums[start] + nums[end] + nums[i] > 0){
                end--;
            }else if(nums[start] + nums[end] + nums[i] < 0){
                start++;
            }else{
                res.push_back({nums[i], nums[start], nums[end]});
                start++;
                end--;

                while(start < end && nums[start] == nums[start - 1]) start++;
                while(start < end && nums[end] == nums[end + 1]) end--;
            }
        }
    }
};
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         sort(nums.begin(), nums.end());

//         vector<vector<int>> ans;
//         int n = nums.size();

//         for (int i = 0; i < n - 2; i++) {

//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;

//             int left = i + 1;
//             int right = n - 1;

//             while (left < right) {

//                 int sum = nums[i] + nums[left] + nums[right];

//                 if (sum == 0) {

//                     ans.push_back({nums[i], nums[left], nums[right]});

//                     while (left < right && nums[left] == nums[left + 1])
//                         left++;

//                     while (left < right && nums[right] == nums[right - 1])
//                         right--;

//                     left++;
//                     right--;
//                 }
//                 else if (sum < 0) {
//                     left++;
//                 }
//                 else {
//                     right--;
//                 }
//             }
//         }

//         return ans;
//     }
// };