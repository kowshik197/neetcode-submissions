class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        // Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Store {query, original index}
        vector<pair<int,int>> qs;

        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        // Sort queries
        sort(qs.begin(), qs.end());

        // {size, end}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for (auto [q, index] : qs) {

            // Add all intervals whose start <= q
            while (i < intervals.size() &&
                   intervals[i][0] <= q) {

                int l = intervals[i][0];
                int r = intervals[i][1];

                int size = r - l + 1;

                pq.push({size, r});

                i++;
            }

            // Remove intervals that cannot contain q
            while (!pq.empty() &&
                   pq.top().second < q) {

                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};