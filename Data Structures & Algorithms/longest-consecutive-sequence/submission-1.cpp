#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        // Store all unique numbers in an unordered set for O(1) average lookup
        std::unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : st) {
            // Only start counting sequence if 'num' is the beginning of a sequence
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentLen = 1;

                // Count consecutive numbers forward
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLen++;
                }

                maxLen = std::max(maxLen, currentLen);
            }
        }

        return maxLen;
    }
};