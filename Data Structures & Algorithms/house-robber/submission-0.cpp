class Solution {
public:
    int size;

    int rob_dp(int i,vector<int>& nums,vector<int>& dp){
     if(i>=size){
        return 0;
     }
     if(dp[i]!=-1){
        return dp[i];
     }
      
      dp[i]=max(nums[i]+rob_dp(i+2,nums,dp),rob_dp(i+1,nums,dp));
      return dp[i];
    }

    int rob(vector<int>& nums) {

        size=nums.size();
        vector<int> memo(size,-1);
        return rob_dp(0,nums,memo);
         
    }
};