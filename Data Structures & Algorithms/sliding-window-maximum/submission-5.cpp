class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;

        vector<int> ans;

        int l = 0;
        int r = 0;

        while (r < nums.size()) {

            // Grow the window
            pq.push({nums[r], r});
            r++;

            // Window has reached size k
            if (r - l == k) {

                // Remove elements outside current window
                while (!pq.empty() && pq.top().second < l) {
                    pq.pop();
                }

                // Update answer
                ans.push_back(pq.top().first);

                // Shrink the window
                l++;
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