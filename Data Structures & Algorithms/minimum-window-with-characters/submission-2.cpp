class Solution {
public:
    string minWindow(string s, string t) {

        int l = 0, r = 0;

        unordered_map<char, int> missing;

        for (char c : t)
            missing[c]++;

        int distinctMissing = missing.size();

        int minLen = INT_MAX;
        int start = 0;

        while (true) {

            bool mustGrow = (distinctMissing > 0);

            if (mustGrow) {

                if (r == s.size())
                    break;

                if (missing.count(s[r])) {

                    missing[s[r]]--;

                    if (missing[s[r]] == 0)
                        distinctMissing--;
                }

                r++;

            } else {

                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }

                if (missing.count(s[l])) {

                    missing[s[l]]++;

                    if (missing[s[l]] == 1)
                        distinctMissing++;
                }

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};