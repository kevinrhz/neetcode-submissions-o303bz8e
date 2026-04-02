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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        // if both lists exist, merge the lowest values onto new dummy node
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next; // advance to next node to continue building
        }

        // once either list1 or list2 reaches nullptr and breaks while loop
        // attach the rest of the opposite list to the node and call it a day.
        if (!list1) {
            node->next = list2;
        } else {
            node->next = list1;
        }

        return dummy.next;
    }
};
