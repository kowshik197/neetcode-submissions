class Solution {
public:
    string s = "", t = "";
    vector<vector<int>> dp;
    int f(int i,int j){

        if(j == t.size())    // t is finished, the remaining characters of s must be deleted:
            return s.size() - i;

        if(i == s.size())
            return t.size() - j;// If s is finished, you must insert all remaining characters of t:

        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i]==t[j]){
           dp[i][j]= f(i+1,j+1);
        }
        else{
            dp[i][j]=1 + min({
    f(i+1,j),      // delete
    f(i,j+1),      // insert
    f(i+1,j+1)     // replace
});

        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        this->s = word1;
        this->t = word2;
        dp.assign(m+1, vector<int>(n+1, -1));
        return f(0,0);
    }
};