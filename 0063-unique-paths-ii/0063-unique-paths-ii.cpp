class Solution {
public:
    int m, n;

    int solve(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {

        if (row >= m || col >= n) {
            return 0;
        }

        if (obstacleGrid[row][col] == 1) {
            return 0;
        }

        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int right = solve(row, col + 1, obstacleGrid, dp);
        int down = solve(row + 1, col, obstacleGrid, dp);

        return dp[row][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, obstacleGrid, dp);
    }
};