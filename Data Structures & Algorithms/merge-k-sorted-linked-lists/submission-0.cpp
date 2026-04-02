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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Edge case: If they hand us zero lists, return nothing.
        if (lists.empty()) return nullptr;

        // The "Divide and Conquer" Engine
        // Keep merging pairs until only 1 massive list remains
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            
            // Jump by 2 every time to grab pairs of lists (e.g., 0 and 1, 2 and 3)
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                
                // Safety check: If we have an odd number of lists, the last one 
                // gets paired with nullptr (which just returns itself when merged)
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                
                // Merge the pair and store the result in our temporary pile
                mergedLists.push_back(mergeList(l1, l2));
            }
            // Overwrite the old, fragmented lists with our new, larger merged chunks
            lists = mergedLists;
        }
        
        // The last remaining list is our fully sorted masterpiece
        return lists[0];
    }

private:
    // This is the exact same "Merge Two Sorted Lists" helper you already mastered!
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy;         // Stack-allocated dummy anchor
        ListNode* tail = &dummy; // The "Advancer" worker pointer

        // While both lists still have nodes to compare
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1; // Link to l1
                l1 = l1->next;   // Move l1 forward
            } else {
                tail->next = l2; // Link to l2
                l2 = l2->next;   // Move l2 forward
            }
            tail = tail->next;   // ALWAYS move the worker forward!
        }

        // Attach whatever is leftover from the longer list
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }

        return dummy.next;
    }
};