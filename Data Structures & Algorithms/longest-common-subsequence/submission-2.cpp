
class Solution {
public:
vector<vector<int>> memo;
int lcs(string& s, string& t, int i, int j){

        if(i == s.size() || j == t.size()){
            return 0;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(s[i] == t[j]){
            memo[i][j] = 1 + lcs(s,t,i+1,j+1);
                    }
        else{
            memo[i][j] = max(lcs(s,t,i+1,j),lcs(s,t,i,j+1));
        }

        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(
            text1.size(),
            vector<int>(text2.size(),-1)
        );
        return lcs(text1,text2,0,0);
    }
};