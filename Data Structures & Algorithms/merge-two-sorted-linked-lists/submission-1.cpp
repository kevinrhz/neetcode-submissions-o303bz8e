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
        // 1. The Dummy Node (The Anchor)
        // We create a fake node on the STACK (not heap, so no memory leak).
        // This saves us from writing 10 lines of messy "if head is null" edge cases.
        ListNode dummy(0);
        
        // 2. The Builder (The Tail Pointer)
        // This pointer always sits at the very end of our newly merged list.
        ListNode* node = &dummy;

        // 3. The Comparison Loop
        // Keep going as long as BOTH piles still have bricks.
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;   // Attach the smaller brick
                list1 = list1->next;  // Move down list1
            } else {
                node->next = list2;   // Attach the smaller brick
                list2 = list2->next;  // Move down list2
            }
            // Move our builder to the newly added brick so it's ready for the next one
            node = node->next;
        }

        // 4. The Leftovers
        // Once the while loop breaks, ONE of the lists is empty.
        // We just take the entire remainder of the other list and snap it on.
        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        // 5. The Return
        // 'dummy' is our fake starting node. 'dummy.next' is the ACTUAL start of the merged list.
        return dummy.next;
    }
};
