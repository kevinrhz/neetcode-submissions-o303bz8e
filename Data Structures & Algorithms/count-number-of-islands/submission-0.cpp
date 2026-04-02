class Solution {
    // (left, right, up, down)
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        // iterate over whole grid, call dfs recursively and increment island if '1' is found
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void dfs(std::vector<std::vector<char>>& grid, int r, int c) {
        // shield against jumping of top, left, bottom, and right of board. also check if water.
        if (r < 0 || c < 0 || r >= grid.size() || 
            c >= grid[0].size() || grid[r][c] == '0')
        {
            return;
        }

        // mark as visited '0'
        grid[r][c] = '0';

        // check all four directions recursively.
        for (int i = 0; i < 4; ++i) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
        
    }
};