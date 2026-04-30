class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> res(n - k + 1); 
        
        // The deque will store INDICES, not the actual values.
        // It maintains a "monotonic decreasing" order of the values those indices point to.
        // This means nums[q.front()] will ALWAYS be the maximum value in the current window.
        std::deque<int> q; 
        
        int l = 0, r = 0;
        while (r < n) {
            // STEP 1: MAINTAIN MONOTONIC DECREASING PROPERTY
            // While the deque is not empty AND the current number we are looking at (nums[r])
            // is GREATER than the number at the back of the deque...
            while (!q.empty() && nums[q.back()] < nums[r]) {
                // ...pop the back of the deque. 
                // Why? Because those smaller numbers are useless now. nums[r] is bigger 
                // AND it's further to the right, meaning it will survive in the window longer.
                q.pop_back(); 
            }
            
            // Push the current INDEX onto the deque.
            q.push_back(r);

            // STEP 2: REMOVE EXPIRED ELEMENTS
            // Check if the index at the front of the deque (our current maximum)
            // has fallen behind our left pointer 'l'. If it has, it's no longer in the window.
            if (l > q.front()) {
                q.pop_front();
            }

            // STEP 3: RECORD THE RESULT AND SHRINK
            // We only want to start recording answers once our window has reached size 'k'.
            // Since 'r' starts at 0, (r + 1) is the count of elements we've seen so far.
            if ((r + 1) >= k) {
                // The front of the deque always holds the index of the max value.
                res[l] = nums[q.front()];
                
                ++l; 
            }
            ++r;
        }
        
        return res;
    }
};