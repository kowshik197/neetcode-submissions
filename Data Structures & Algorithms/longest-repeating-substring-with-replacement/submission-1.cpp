class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0, r = 0;
        int curr_best = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        while (r < s.size()) {

            // Include current character
            freq[s[r] - 'A']++;

            // Update maximum frequency in current window
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            r++;

            // If window becomes invalid, shrink it
            while ((r - l  ) - maxFreq > k) {

                freq[s[l] - 'A']--;
                l++;
            }

            // Update answer
            curr_best = max(curr_best, r - l );

            // Expand window
        }

        return curr_best;
    }
};