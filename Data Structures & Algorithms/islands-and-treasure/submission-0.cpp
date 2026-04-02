class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // find all the treasures and store in queue
        int ROWS = grid.size(), COLS = grid[0].size();
        std::queue<int> q;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == 0) q.push(i * COLS + j);
            }
        }

        static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            // grab the row and col position of next treasure, then pop from stack
            int cur = q.front(); q.pop();
            int row = cur / COLS;
            int col = cur % COLS;

            // iterate over the four directions
            for (int i = 0; i < 4; ++i) {
                // calculate next r and c value at next direction
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                // shield against out of bounds spaces and any space that isnt walkable (INF)
                if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1; // update cells value
                q.push(r * COLS + c); // push current cell for next bfs iteration
            }
        }
    }
};
