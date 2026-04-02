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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // create n sized gap
        while (n > 0) {
            fast = fast->next;
            --n;
        }

        // slide the gap to the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // perform surgery with gap in place
        slow->next = slow->next->next;

        // return safe anchor
        return dummy.next;
    }
};
