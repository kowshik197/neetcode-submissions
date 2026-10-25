
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
            r++;

            // Calculate the actual maximum frequency
            maxFreq = 0;
            for (int i = 0; i < 26; i++) {
                maxFreq = max(maxFreq, freq[i]);
            }

            // Shrink while invalid
            while ((r - l) - maxFreq > k) {

                freq[s[l] - 'A']--;
                l++;

                // Recalculate maxFreq after shrinking
                
                maxFreq = 0;
                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
            }

            // Update answer
            curr_best = max(curr_best, r - l);
        }

        return curr_best;
    }
};
