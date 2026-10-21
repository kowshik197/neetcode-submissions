class Solution {
public:
    vector<string> result;

    void backtrack(string& path, int open, int close, int n) {

        // Base Case
        if (path.size() == 2 * n) {
            result.push_back(path);
            return;
        }

        // Choice 1: Add '('
        if (open < n) {
            path.push_back('(');
            backtrack(path, open + 1, close, n);
            path.pop_back();
        }

        // Choice 2: Add ')'
        if (close < open) {
            path.push_back(')');
            backtrack(path, open, close + 1, n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string path = "";

        backtrack(path, 0, 0, n);

        return result;
    }
};