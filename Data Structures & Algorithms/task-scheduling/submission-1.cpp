class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        // Count frequency of each task
        for (char ch : tasks) {
            freq[ch]++;
        }

        // Max Heap
        priority_queue<int> pq;

        for (auto it : freq) {
            pq.push(it.second);
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;
            int cycle = n + 1;

            // Execute at most (n+1) tasks
            while (cycle > 0 && !pq.empty()) {

                int cnt = pq.top();
                pq.pop();

                cnt--;

                if (cnt > 0)
                    temp.push_back(cnt);

                time++;
                cycle--;
            }

            // Push remaining frequencies back
            for (int x : temp) {
                pq.push(x);
            }

            // If tasks are still remaining,
            // the unused slots become idle time.
            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};