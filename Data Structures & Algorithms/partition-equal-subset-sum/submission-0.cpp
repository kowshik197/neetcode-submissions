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

        dp[i][target]= f(i+1,target-nums[i]) || f(i+1,target);
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
