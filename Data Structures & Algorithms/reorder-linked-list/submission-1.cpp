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
        // Kick off the "Rubber Band". 
        // 'head' stays at the front, 'head->next' starts stretching toward the tail.
        head = rec(head, head->next);
    }

private:
    // 'root': Moves FORWARD during the unwinding phase.
    // 'cur': Moves BACKWARD during the unwinding phase (via the call stack).
    ListNode* rec(ListNode* root, ListNode* cur) {
        // 1. Base Case (Maximum Stretch)
        // We hit the tail of the list. Return the 'root' (front of list) to start the wiring.
        if (cur == nullptr) return root;

        // 2. The Dive (Stretch the rubber band)
        // Keep pushing 'cur' deeper. When it unwinds, 'root' is overwritten with the NEXT front node.
        root = rec(root, cur->next);

        // 3. The Stop Signal Propagation
        // If a deeper level returned nullptr, it means the list is finished. Pass the signal up.
        if (root == nullptr) return nullptr;

        ListNode* tmp = nullptr;

        // 4. The Collision (Meeting in the middle)
        // Have the front pointer (root) and back pointer (cur) met or crossed?
        if (root == cur || root->next == cur) {
            cur->next = nullptr; // Terminate the list here to prevent an infinite cycle!
            // Note: tmp remains nullptr. This acts as the "Stop Signal" for the levels above.
        } 
        // 5. The Wiring (Zip them together)
        else {
            tmp = root->next;   // Save the next front node for the next unwinding step
            root->next = cur;   // Link Front -> Back (e.g., L1 -> Ln)
            cur->next = tmp;    // Link Back -> Next Front (e.g., Ln -> L2)
        }

        // 6. The Return
        // Hand the 'tmp' node up the stack. 
        // This becomes the new 'root' for the level above us!
        return tmp;
    }
};
