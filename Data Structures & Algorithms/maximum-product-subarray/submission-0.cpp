class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int prevMax = maxProd;
            int prevMin = minProd;

            maxProd = max({
                nums[i],
                nums[i] * prevMax,
                nums[i] * prevMin
            });

            minProd = min({
                nums[i],
                nums[i] * prevMax,
                nums[i] * prevMin
            });

            ans = max(ans, maxProd);
        }

        return ans;
    }
};