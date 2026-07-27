// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         unordered_map<int, int> freq;

//         // Count frequency
//         for (int num : nums) {
//             freq[num]++;
//         }

//         // Max Heap -> {frequency, number}
//         priority_queue<pair<int, int>> pq;

//         for (auto it : freq) {
//             pq.push({it.second, it.first});
//         }

//         vector<int> ans;

//         while (k--) {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }

//         return ans;
//     }
// };

//Bucket sort 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();

        // bucket[i] stores elements occurring i times
        vector<vector<int>> bucket(n + 1);

        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        // Traverse from highest frequency
        for (int i = n; i >= 1 && ans.size() < k; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};