class Solution {
public:
    int n;
    vector<vector<int>> dp;
    vector<int> nums;
    bool f(int i,int target){
        if(target==0){
            return true;
        }
        if(target<0){
            return false;
        }
        if(i>=n){
            return false;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        bool pick=f(i+1,target-nums[i]);
        bool skip=f(i+1,target);

        dp[i][target]= pick || skip;
                cout<<dp[i][target];

        return dp[i][target];


    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
       int size=nums.size();
       n=size;
        for(int i=0;i<size;i++){
         sum+=nums[i];
        }
        this->nums=nums;

        if(sum%2!=0){
            return false;
        }

        int target=sum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        this->dp=dp;
        return f(0,target);
    }
};



/*

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (const auto num : nums)
            sum += num;
        if (sum % 2 != 0)
            return false;
        sum /= 2;

        return dfs(nums, 0, 0, sum);
    }

    bool dfs(vector<int>& nums, int index, int cur_sum, int target) {
        if (index == nums.size()) {
            if (cur_sum == target) 
                return true;
            return false;
        }
        if (cur_sum > target)
            return false;

        if (dfs(nums, index + 1, cur_sum + nums[index], target))
            return true;
        if (dfs(nums, index + 1, cur_sum, target))
            return true;
        return false;
    }
};

*/
