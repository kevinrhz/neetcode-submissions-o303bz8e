class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        
        // OPTIMIZATION 1: Flattened Queue
        // Using `int` instead of `pair<int,int>` cuts memory footprint in half 
        // and is highly cache-friendly for the CPU.
        std::queue<int> q;
        
        // LOGIC: Multi-Source BFS 
        // We push ALL treasures first. This guarantees the BFS ripples out evenly,
        // so the first time a room is reached, it is mathematically the shortest path.
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 0) q.push(i * COLS + j);
            }
        }

        // OPTIMIZATION 2: static constexpr
        // Evaluates at compile-time and stores in read-only memory once, 
        // preventing stack reallocation on every function call.
        static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            
            // Decode the flattened 1D coordinate back into 2D row/col
            int row = cur / COLS;
            int col = cur % COLS;

            for (int i = 0; i < 4; ++i) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                // LOGIC: The `!= INT_MAX` check is our "Visited" Shield.
                // It ensures we only process empty, unvisited rooms. 
                // Once a room is given a distance, it is no longer INT_MAX and is skipped.
                if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != INT_MAX) {
                    continue;
                }

                // OPTIMIZATION 3: In-Place Updates
                // Overwriting the grid directly saves us from having to allocate 
                // an entirely separate `O(M * N)` visited matrix.
                grid[r][c] = grid[row][col] + 1; 
                
                // Flatten the NEW neighbor's coordinates and push it to the queue
                q.push(r * COLS + c); 
            }
        }
    }
};