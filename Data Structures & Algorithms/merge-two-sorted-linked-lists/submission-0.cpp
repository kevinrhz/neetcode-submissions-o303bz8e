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
        // 1. Base Cases (The "Leftovers")
        // If one list is empty, just return the entire remainder of the other list.
        if (!list1) return list2;
        if (!list2) return list1;

        // 2. The Decision: Which brick is smaller? That one goes next.
        if (list1->val <= list2->val) {
            // 3. The Delegation & Connection: 
            // "Master Builder, figure out the rest of the list and attach it to my 'next'."
            list1->next = mergeTwoLists(list1->next, list2);
            
            // 4. The Return (Unwinding): 
            // Hand this fully connected node back up the chain to the caller.
            return list1;
        } else {
            // Same logic, but list2 won the comparison so it becomes the current node.
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
