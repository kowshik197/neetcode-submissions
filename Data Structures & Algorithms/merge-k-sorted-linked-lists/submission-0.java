/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        PriorityQueue<ListNode> pq =
            new PriorityQueue<>((a, b) -> a.val - b.val);

        // Put first node of every list
        for (ListNode node : lists) {
            if (node != null) {
                pq.offer(node);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {

            // Get smallest node
            ListNode curr = pq.poll();

            // Add it to answer
            tail.next = curr;
            tail = tail.next;

            // Put next node of same list into heap
            if (curr.next != null) {
                pq.offer(curr.next);
            }
        }

        return dummy.next;
    }
}