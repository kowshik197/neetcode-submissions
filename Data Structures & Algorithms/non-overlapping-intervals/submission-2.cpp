class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        vector<vector<int>> ans;

        for (auto &curr : intervals) {

            if (ans.empty() || ans.back()[1] <= curr[0]) {
                ans.push_back(curr);
            }
        }

        return intervals.size() - ans.size();
    }
};