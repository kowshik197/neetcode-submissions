class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Put first node of every list
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* curr = pq.top();
            pq.pop();

            // Add to answer
            tail->next = curr;
            tail = curr;

            // Add next node from the same list
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};