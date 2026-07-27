class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int size = nums.size();
        vector<int> preMul(size);
        vector<int> sufMul(size);
        vector<int> ans(size);
        preMul[0] = 1;
        for (int i = 1; i < size; i++) {
            preMul[i] = preMul[i - 1] * nums[i - 1];
        }

        sufMul[size - 1] = 1;
        for (int i = size - 2; i >= 0; i--) {
            sufMul[i] = sufMul[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; i++) {
            ans[i] = preMul[i] * sufMul[i];
        }

        return ans;
    }
};
