class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Push {value, index}
            pq.push({nums[i], i});

            // Remove elements outside the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // First window formed
            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {

//         deque<int> dq;      // Stores indices
//         vector<int> ans;

//         for (int i = 0; i < nums.size(); i++) {

//             // Remove indices outside the current window
//             while (!dq.empty() && dq.front() <= i - k)
//                 dq.pop_front();

//             // Remove smaller elements from the back
//             while (!dq.empty() && nums[dq.back()] <= nums[i])
//                 dq.pop_back();

//             // Insert current index
//             dq.push_back(i);

//             // Window formed
//             if (i >= k - 1)
//                 ans.push_back(nums[dq.front()]);
//         }

//         return ans;
//     }
// };