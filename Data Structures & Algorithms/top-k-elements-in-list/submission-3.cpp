class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Max Heap -> {frequency, number}
        priority_queue<pair<int, int>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        vector<int> ans;

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};