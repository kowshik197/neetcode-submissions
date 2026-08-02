class Solution {
public:

    int start = 0;
    int maxLen = 1;

    void expand(string& s, int left, int right) {

        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right]) {

            int len = right - left + 1;

            if(len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        int n = s.size();

        if(n == 0) {
            return "";
        }

        for(int i = 0; i < n; i++) {

            // odd length
            expand(s, i, i);

            // even length
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
