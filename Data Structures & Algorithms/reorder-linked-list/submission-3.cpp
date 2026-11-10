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
    void reorderList(ListNode* head) {
        // Find middle of list
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half of list
        ListNode* cur = slow->next, *prev = slow->next = nullptr;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // Merge the two halves into result
        ListNode* first = head, *second = prev;
        while (second) {
            ListNode* firstNxt = first->next, *secondNxt = second->next;
            first->next  = second;
            second->next = firstNxt;
            first  = firstNxt;
            second = secondNxt;
        }
    }
};
