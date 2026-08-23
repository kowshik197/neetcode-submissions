class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> last;

        // Store last occurrence
        for(int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++) {

            // Current partition must extend
            // until the last occurrence of s[i]
            end = max(end, last[s[i]]);

            // We have reached the end of partition
            if(i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};