class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    
    int n = nums.size();
  int currMax = 0, maxSum = nums[0];

        for (int x : nums) {
            // Kadane for maximum
            currMax = max(x, currMax + x);

            maxSum = max(maxSum, currMax);
        }

    return maxSum;
}


};