class Solution {
public:
    bool is_before(int mid, vector<int>& nums, int target) {
        return nums[mid] < target;
    }

    int search(vector<int>& nums, int target) {

        // Empty range
        if (nums.empty()) return -1;

        int l = 0;
        int r = nums.size() - 1;

        // Whole range is 'after'
        if (!is_before(l, nums, target)) {
            return (nums[l] == target) ? l : -1;
        }

        // Whole range is 'before'
        if (is_before(r, nums, target)) {
            return -1;
        }

        while (r - l > 1) {
            int mid = (l + r) / 2;

            if (is_before(mid, nums, target))
                l = mid;
            else
                r = mid;
        }

        // r is the first element >= target
        return (nums[r] == target) ? r : -1;
    }
};