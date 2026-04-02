class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(), COLS = matrix[0].size();

        // Treat the 2D matrix as a single, contiguous 1D array in memory.
        // Note: For massive production databases, use 'long long' to prevent ROWS * COLS overflow.
        int l = 0, r = ROWS * COLS - 1;
        
        while (l <= r) {
            // Calculate midpoint safely to prevent (l + r) integer overflow
            int m = l + (r - l) / 2;
            
            // Map the virtual 1D index back to 2D logical coordinates using division and modulo
            int row = m / COLS; 
            int col = m % COLS;
            
            // Standard binary search: aggressively halve the search space
            if (target > matrix[row][col]) {
                l = m + 1;
            } else if (target < matrix[row][col]) {
                r = m - 1;
            } else {
                return true; // Target found
            }
        }
        return false;
    }
};