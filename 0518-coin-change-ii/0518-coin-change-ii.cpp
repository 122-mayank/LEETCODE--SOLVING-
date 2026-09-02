class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int idx) {

        // We have successfully formed the amount
        if (amount == 0) {
            return 1;
        }

        // No coins left
        if (idx >= coins.size()) {
            return 0;
        }

        // Already calculated
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int take = 0;
        int skip = 0;

        // Take current coin
        if (coins[idx] <= amount) {
            take = solve(coins, amount - coins[idx], idx);
        }

        // Skip current coin
        skip = solve(coins, amount, idx + 1);

        return dp[idx][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        return solve(coins, amount, 0);
    }
};