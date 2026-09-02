class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {

        Stack<ListNode> st = new Stack<>();

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while (head != null) {

            // Collect exactly k nodes
            ListNode temp = head;
            int count = 0;

            while (temp != null && count < k) {
                st.push(temp);
                temp = temp.next;
                count++;
            }

            // Less than k nodes -> don't reverse
            if (count < k) {
                curr.next = head;
                break;
            }

            // Reverse the k nodes
            while (!st.isEmpty()) {
                ListNode node = st.pop();

                curr.next = node;
                curr = node;
            }

            // Move to next group
            head = temp;

            // Break old connection
            curr.next = null;
        }

        return dummy.next;
    }
}