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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // initialize dummy onto stack for cleaner ops
        ListNode dummy(0);
        ListNode* cur = &dummy;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) { // keep loop spinning if for any remaining possible values
            // retrieve l1 and l2 value. pass 0 to continue arithmetic without segfault since main loop spins for many cases
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            // calculate sum with carry.
            int sum = v1 + v2 + carry;
            // isolate carry value and sum value.
            carry = sum / 10;
            sum = sum % 10;
            // set next node to a new node with value initialized to isolated sum
            cur->next = new ListNode(sum);

            // increment l1 and l2. but if its already at nullptr, just keep it there
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            cur = cur->next;
        }

        return dummy.next;
    }
};
