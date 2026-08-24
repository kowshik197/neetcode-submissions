class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0; int right = nums.size()-1;

        while(left<right){
            int mid = (right + left)/2 ;
            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
        
    }
};
/*
class Solution {
public:
    bool is_before(int i, vector<int>& nums) {
        return nums[i] > nums.back();
    }

    int findMin(vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int r = n - 1;

        // Entire array is already sorted
        if (!is_before(l, nums))
            return nums[l];

        while (r - l > 1) {

            int mid = l + (r - l) / 2;

            if (is_before(mid, nums))
                l = mid;
            else
                r = mid;
        }

        return nums[r];
    }
};
*/