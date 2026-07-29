class MedianFinder {
public:

    // Lower half (largest element on top)
    priority_queue<int> max_heap;

    // Upper half (smallest element on top)
    priority_queue<int, vector<int>, greater<int>> min_heap;

    MedianFinder() {

    }

    void addNum(int num) {

        // Step 1: Insert into max heap
        max_heap.push(num);

        // Step 2: Move largest of lower half to upper half
        min_heap.push(max_heap.top());
        max_heap.pop();

        // Step 3: Balance heaps
        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {

        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }

        return (max_heap.top() + min_heap.top()) / 2.0;
    }
};