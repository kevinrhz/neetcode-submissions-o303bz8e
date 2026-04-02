class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1. The Setup: 
        // Index = "Memory Address" | Value = "->next pointer"
        int slow = 0, fast = 0;
        
        // 2. Phase 1: Enter the Cycle
        // We use while(true) so they take their first step BEFORE checking if they meet,
        // otherwise they would immediately trigger slow == fast at index 0.
        while (true) {
            slow = nums[slow];          // Move 1 step (Read the sign, go to that gate)
            fast = nums[nums[fast]];    // Move 2 steps (Read the sign, go to next, read that sign)
            
            // They collided somewhere inside the loop. The cycle exists.
            if (slow == fast) break;
        }

        // 3. Phase 2: Find the Duplicate (The Cycle Entrance)
        // Floyd's Math guarantees that the distance from the Start to the Entrance 
        // is the SAME as the distance from the Collision Point to the Entrance.
        int slow2 = 0; // Start a new pointer at the very beginning
        
        while (true) {
            slow = nums[slow];   // Move original slow 1 step from collision point
            slow2 = nums[slow2]; // Move new slow 1 step from the start
            
            // The exact gate where they crash into each other is the duplicate!
            if (slow == slow2) {
                return slow;
            }
        }
    }
};