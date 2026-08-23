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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* slow=nullptr;
    ListNode* temp = head;
    ListNode* rev=reverseList(temp);
    int count =1;
     if (n == 1) {
            ListNode* toDelete = rev;
            rev = rev->next;
            delete toDelete;
            return reverseList(rev);
        }
     ListNode* curr=rev;
    while(count!=n && curr!=nullptr){
      slow=curr;    
      curr=curr->next;

count++;
    }

        slow->next=curr->next;
        return reverseList(rev);


    }

    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
};