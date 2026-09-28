class Solution {
public:


    priority_queue<int> max_heap;

    priority_queue<int, vector<int>, greater<int>> min_heap;

    void addNum(int num) {

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




    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

   
        for(int &n:nums1){
         addNum(n);
        }

        for(int &n:nums2){
         addNum(n);
        }

        return findMedian();


    }
};