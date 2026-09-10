
class Solution {
public:

    int start = 0;
    int maxLen = 1;
    int count=0;
    void expand(string& s, int left, int right) {

        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right]) {

            // int len = right - left + 1;

            // if(len > maxLen) {
            //     maxLen = len;
            //     start = left;
            // }
            count++;

            left--;
            right++;
        }
    }

    int countSubstrings(string s) {

        int n = s.size();

        if(n == 0) {
            return 0;
        }

        for(int i = 0; i < n; i++) {

            // odd length
            expand(s, i, i);

            // even length
            expand(s, i, i + 1);
        }

        return count;
    }
};
