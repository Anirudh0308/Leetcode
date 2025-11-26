class Solution {
public:

    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int row, int col, int remain, vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m || col >= n)
            return 0;

        if(row == m - 1 && col == n - 1)
            return ((remain + grid[row][col]) % k == 0);

        if(t[row][col][remain] != -1)
            return t[row][col][remain];

        int newRemain = (remain + grid[row][col]) % k;

        int down  = solve(row + 1, col, newRemain, grid, k);
        int right = solve(row, col + 1, newRemain, grid, k);

        return t[row][col][remain] = (down + right) % M;
    }



    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k);
    }
};