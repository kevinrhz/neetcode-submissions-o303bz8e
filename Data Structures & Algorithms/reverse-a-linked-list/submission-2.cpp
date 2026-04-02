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
    ListNode* reverseList(ListNode* head) {
        // 1. Base Case: If we hit the end, this node is the NEW FRONT of the list.
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }

        // 2. The Search: Go find the very last node and bring it back as 'newFront'.
        // We don't touch 'newHead' again; we just pass it up the stack.
        ListNode* newHead = reverseList(head->next);

        // 3. The Reversal:
        // 'head' is the Current Node.
        // 'head->next' is the Immediate Neighbor (the node in front of us).
        // We tell that neighbor: "Point your 'next' arrow back at me."
        head->next->next = head;

        // 4. The Clean-up:
        // Break our old forward-pointing arrow so we don't create a loop.
        head->next = nullptr;

        // 5. Return the 'newHead' (which is still Node 3) all the way to the start.
        return newHead;
    }
};
