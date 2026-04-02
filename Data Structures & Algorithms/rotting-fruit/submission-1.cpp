class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        std::queue<int> q;

        // count num of fresh fruit, and push rotten fruit to queue
        int fresh = 0;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 1) ++fresh;
                else if (grid[r][c] == 2) q.push(r * COLS + c);
            }
        }

        int time = 0;
        static constexpr  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // while queue isnt empty and fresh fruit exist
        while (!q.empty() && fresh > 0) {
            // iterate the queue size each iteration for the adjacent fruits
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front(); q.pop();
                int r = cur / COLS, c = cur % COLS;

                // serach all directions, if in bounds and isnt fresh, then make rotten and push adjacent fruits
                for (const auto& dir : dirs) {
                    int row = r + dir[0];
                    int col = c + dir[1];
                    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || grid[row][col] != 1) {
                        continue;
                    }

                    grid[row][col] = 2;
                    q.push(row * COLS + col);
                    --fresh;
                }
            }
            ++time;
        }
        return fresh == 0 ? time : -1;
    }
};
