/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Step 2: Find cycle beginning
                // slow = head;

                // while (slow != fast) {
                //     slow = slow->next;
                //     fast = fast->next;
                // }
                 return true;
                // return slow;
            }
        }

        // return nullptr;
        return false;
    }
};


// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {

//         ListNode* slow = head;
//         ListNode* fast = head;

//         // Step 1: Detect cycle
//         while (fast != nullptr && fast->next != nullptr) {

//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) {

//                 // Step 2: Find cycle beginning
//                 slow = head;

//                 while (slow != fast) {
//                     slow = slow->next;
//                     fast = fast->next;
//                 }

//                 return slow;
//             }
//         }

//         return nullptr;
//     }
// };