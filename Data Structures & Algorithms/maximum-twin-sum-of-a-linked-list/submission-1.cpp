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
    int pairSum(ListNode* head) {
        // Find the midpoint/two halves and reverse the first half while traversing
        ListNode* slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        // Compute the two halves max pair values
        int res = 0;
        while (prev) {
            res = std::max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }
        return res;
    }
};