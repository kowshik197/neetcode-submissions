class Solution {
public:
    int size;

    int rob_dp(int i,int reach,vector<int>& nums,vector<int>& dp,string str){
     if(i>=reach){
        return 0;
     }
     if(dp[i]!=-1){
        return dp[i];
     }
      
      dp[i]=max(nums[i]+rob_dp(i+2,reach,nums,dp,str),rob_dp(i+1,reach,nums,dp,str));
      cout<<"Dp ans:"<<dp[i]<<" ,"<<"Function Running"<<str<<", i:"<<i<<endl;
      return dp[i];
    }

    int rob(vector<int>& nums) {

        size=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> memo(size,-1);
        vector<int> memo1(size,-1);
        

        string fn1="fn1";
        string fn2="fn2";

        int first  = rob_dp(0,size-1,nums,memo,fn1);
        int second = rob_dp(1,size,nums,memo1,fn2);
        return max(first,second);

         
    }
};