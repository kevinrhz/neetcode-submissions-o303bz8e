class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void bfs(std::vector<std::vector<char>>& grid, int r, int c) {
        std::queue<std::pair<int, int>> q;

        // flip initial node to '0' and push it to queue
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty()) {
            // grab and pop node from front of queue
            auto node = q.front(); q.pop();

            // Move in all directions with breadth
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; ++i) {
                // grab nodes next rows and columns
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];

                // look all directions before jumping. ensure its a piece of island '1'
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1')
                {
                    // push each direction that passes all checks and flip it to '0'
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }

    }
};
