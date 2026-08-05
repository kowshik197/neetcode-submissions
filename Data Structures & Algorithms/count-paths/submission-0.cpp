class Solution {
public:
    int R=0;
    int C=0;
    int ans=0;
    vector<vector<int>> dp;
    int f(int r,int c){

        if(r==R-1 && c==C-1){
                   
            return 1;
          }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
         
        if(r==R-1){
           dp[r][c]=f(r,c+1);
        }

        else if(c==C-1){
          dp[r][c]=f(r+1,c);
        }
          else{
        dp[r][c]=f(r+1,c)+f(r,c+1);
    }
       return dp[r][c];
         
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        this->dp=dp;

        R=m;
        C=n;

        return f(0,0);
    }
};
