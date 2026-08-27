class Solution {
public:

    unordered_set<string> dict;
    vector<int> dp;
    string s;
    int n;

    bool f(int i) {

        if(i == n) {
            return true;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        for(int end = i; end < n; end++) {

            string word = s.substr(i, end - i + 1);

        if (dict.count(word)) {
                        // 2. Separately run the recursive check for end + 1
                        bool canBreakRemainder = f(end + 1);
                        
                        if (canBreakRemainder) {
                            return dp[i] = true;
                        }
                    }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        this->s = s;
        n = s.size();

        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        dp.assign(n, -1);

        return f(0);
    }
};