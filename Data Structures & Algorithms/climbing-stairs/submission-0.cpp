class Solution {
public:
     int n;
     vector<int> memo;
     int f(int i){
        if(i>=n){
            return 1;
        }
        if(memo[i]!=-1){
            return memo[i];
        }

    int ways =0;

    ways+= f(i+1);

    if(i+1<n){
        ways+=f(i+2);
    }
        return memo[i]=ways;


     }
    int climbStairs(int n) {
        this->n=n;
        memo.assign(n,-1);
        return f(0);
    }
};
