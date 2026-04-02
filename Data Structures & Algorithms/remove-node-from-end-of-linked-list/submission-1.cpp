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
        // create two l and r pointers with l initialized to dummy before the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        // move right pointer into n position
        while (n > 0) {
            right = right->next;
            --n;
        }

        // move both pointers into result position
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        // remove the nth node and return resulting dummy->head
        left->next = left->next->next;
        return dummy->next;

    }
};
