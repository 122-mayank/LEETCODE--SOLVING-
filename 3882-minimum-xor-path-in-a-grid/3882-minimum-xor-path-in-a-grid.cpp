class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int res,
              vector<vector<vector<int>>>& dp) {

        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        // Include current cell in XOR
        res ^= grid[i][j];

        // Starting cell reached
        if (i == 0 && j == 0) {
            return res;
        }

        // Memoization uses the updated XOR
        if (dp[i][j][res] != -1) {
            return dp[i][j][res];
        }

        int left = solve(grid, i, j - 1, res, dp);
        int up = solve(grid, i - 1, j, res, dp);

        return dp[i][j][res] = min(left, up);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int MAX_XOR = 1024;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(MAX_XOR, -1)
        ));

        return solve(grid, m - 1, n - 1, 0, dp);
    }
};