class Solution {
public:
    int m, n;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&grid, int row, int col) {

        if(row >= m || row < 0 || col < 0 || col >= n) {
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int up = 1 , left = 1, right = 1 , down = 1;
        // up
        if (row - 1 >= 0 && grid[row-1][col] > grid[row][col]) {
            up = solve(grid, row - 1, col) + 1;
        }

        // down
        if (row + 1 < m && grid[row+1][col] > grid[row][col]) {
            down = solve(grid, row + 1, col) + 1;
        }

        // left
        if (col - 1 >= 0 && grid[row][col-1] > grid[row][col]) {
            left = solve(grid, row, col - 1) + 1;
        }

        // right
        if (col + 1 < n && grid[row][col+1] > grid[row][col]) {
            right = solve(grid, row, col + 1) + 1;
        }

        return dp[row][col] = max(left , max(right , max(up , down)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();
        int maxi = INT_MIN;

        dp.resize(m , vector<int>(n , -1));

        for(int i = m - 1 ; i >= 0 ; i--){
            for(int j = n - 1 ; j >= 0 ; j--){
                maxi = max(maxi , solve(matrix , i , j));
            }
        }

        return maxi;
    }
};