class Solution {
public:
    int num_cols;
    int num_rows;
    vector<vector<char>> grid;
    
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        num_rows = grid.size();
        num_cols = grid[0].size();
        int num_islands = 0;

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (grid[i][j] == '1') {
                    num_islands+= dfs(i, j);
                }
            }
        }
        return num_islands;
    }
    
    int dfs(int i, int j) {
        
        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols) return 0;

        if (grid[i][j] == '0') return 0;

        grid[i][j] = '0';
        dfs(i, j - 1);
        dfs(i, j + 1);
        dfs(i - 1, j);
        dfs(i + 1, j);

        return 1;
    }
};