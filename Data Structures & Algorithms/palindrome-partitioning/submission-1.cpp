class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(int start,string &s,vector<string> &path) {

        // Base Case
        if(start == s.size()) {
            result.push_back(path);
            return;
        }

        // Try every possible cut
        for(int end = start; end < s.size(); end++) {

            // Constraint
            if(!isPalindrome(s, start, end))
                continue;

            // Choose
            path.push_back(s.substr(start, end - start + 1));

            // Explore
            backtrack(end + 1, s, path);

            // Undo
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> path;

        backtrack(0, s, path);

        return result;
    }
};