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




/*

"These tasks were executed in this window,
but they still have remaining copies.
Don't put them back into the heap until
the current n+1 window is finished."

*/




/*
LOGIC:

1. Count the frequency of every task.
   - Example: A A A B B B -> A=3, B=3

2. Put all frequencies into a MAX HEAP.
   - The task with the highest remaining frequency comes first.
   - We don't need the actual task character, only its frequency.

3. Process tasks in windows of size (n + 1).
   - If cooldown = n, after executing a task we need n other CPU cycles
     before executing the same task again.
   - Therefore, one complete cycle/window has n + 1 slots.

4. In each window:
   - Take the most frequent task from the heap.
   - Execute it once -> decrement its frequency.
   - If it still has remaining occurrences, store the remaining frequency
     temporarily in 'temp'.
   - Repeat for at most n + 1 different tasks.

5. After the window is finished:
   - Put all remaining frequencies from 'temp' back into the max heap.
   - If the heap is NOT empty, some tasks are still remaining.
     Therefore, any unused slots in this window must be IDLE cycles.
     Add those idle slots to 'time'.

6. If the heap becomes empty:
   - All tasks are finished.
   - Do NOT add the remaining unused slots, because we don't need to
     wait for cooldown after the final task.

7. Continue until the heap becomes empty.

KEY IDEA:
- MAX HEAP -> always choose the task with the highest remaining frequency.
- n + 1 -> one task + n cooldown positions.
- temp -> holds tasks that still have remaining occurrences so they can
  be used again only in the next window.
- idle time is counted only when tasks are still remaining.

Example:
tasks = [A,A,A,B,B,B], n = 2

Window size = 3

A B idle
A B idle
A B

Total = 8 cycles.

TIME: O(T log 26) ≈ O(T), because there are at most 26 task types.
SPACE: O(26) = O(1).
*/