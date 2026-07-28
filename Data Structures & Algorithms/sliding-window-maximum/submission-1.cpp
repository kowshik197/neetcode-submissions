class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        for (int l = 0; l + k <= nums.size(); l++) {

            int maxNum = INT_MIN;

            for (int i = l; i < l + k; i++) {
                maxNum = max(maxNum, nums[i]);
            }

            ans.push_back(maxNum);
        }

        return ans;
    }
};
