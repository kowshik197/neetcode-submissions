class Solution {
public:
    vector<vector<int>> dp;
    vector<int> arr;
    int f(int l,int r){
        if (l > r){
            return 0;
        }

        if(dp[l][r]!=-1){
            return dp[l][r];
        }

for(int k = l; k <= r; k++) {

    dp[l][r] = max(
        dp[l][r],
        f(l,k-1)
        + arr[l-1] * arr[k] * arr[r+1]
        + f(k+1,r)
    );
}
       return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        int size=nums.size();
        vector<int> arr = {1};

        for(int x : nums){
            arr.push_back(x);
        }
        arr.push_back(1);  
        int n=arr.size();      
        this->arr=arr;
        dp.assign(n,vector<int>(n, -1));
        

/*

index:  0  1  2  3  4  5
arr:   [1, 3, 1, 5, 8, 1]
         ↑           ↑
       boundary    boundary

        f(1,4)


*/

        return f(1,n-2);
        
    }
};
