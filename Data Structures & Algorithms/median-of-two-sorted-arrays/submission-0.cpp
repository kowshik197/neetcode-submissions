class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition found
            if (l1 <= r2 && l2 <= r1) {

                // Odd total elements
                if ((m + n) % 2 == 1)
                    return max(l1, l2);

                // Even total elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Move left
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // Move right
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};