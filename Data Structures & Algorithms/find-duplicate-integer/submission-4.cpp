class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Find cycle
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        // Find intersection of cycle and beginning
        int slow2 = 0;
        while (true) {
            slow  = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) return slow;
        }
    }
};
