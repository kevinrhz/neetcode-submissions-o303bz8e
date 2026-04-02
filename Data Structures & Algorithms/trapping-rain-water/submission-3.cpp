class Solution {
public:
    int trap(vector<int>& height) {
        // OPTIMIZATION 1: IO Speedup (Standard Interview Boilerplate)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = height.size();
        if (n == 0) return 0;

        // OPTIMIZATION 2: Raw Pointer Access
        // - Why: vector::operator[] has debug overhead. 
        // - Raw int* is just a memory address offset.
        int* h = height.data(); 

        int l = 0, r = n - 1;
        int leftMax = h[l], rightMax = h[r];
        int res = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                // OPTIMIZATION 3: Branch instead of Math
                // - Original: max(), then add (max - curr). If max updated, we add 0.
                // - Infra: If new max, just update. Else, add water.
                // - Why: Avoids a useless "add 0" instruction.
                if (h[l] >= leftMax) {
                    leftMax = h[l];
                } else {
                    res += leftMax - h[l];
                }
            } else {
                r--;
                if (h[r] >= rightMax) {
                    rightMax = h[r];
                } else {
                    res += rightMax - h[r];
                }
            }
        }
        return res;
    }
};