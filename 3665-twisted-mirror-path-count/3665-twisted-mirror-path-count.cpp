class Solution {
public:
    int m, n;
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& grid, 
    int i, int j, bool flag,vector<vector<vector<int>>>&dp ) {

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if(dp[i][j][flag] != -1){
            return dp[i][j][flag];
        }

        int right = 0, down = 0;

        if (grid[i][j] == 1 && flag == true) {
            down = solve(grid, i + 1, j, false  , dp);
        }

        else if (grid[i][j] == 1 && flag == false) {
            right = solve(grid, i, j + 1, true , dp);
        } else {
            right = solve(grid, i, j + 1, true , dp);

            down = solve(grid, i + 1, j, false , dp);
        }

        return dp[i][j][flag] = (right + down) % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        bool flag = false;
        dp.assign(m , vector<vector<int>>(n, vector<int>(2 , -1)));
        return solve(grid, 0, 0, flag , dp);
    }
};