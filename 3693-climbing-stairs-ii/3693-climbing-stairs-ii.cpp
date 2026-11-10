
class Solution {
public:

    int solve(int i, vector<int>& costs, vector<int>& dp) {

        // Base case
        if (i == 0) {
            return 0;
        }

        // Already calculated
        if (dp[i] != -1) {
            return dp[i];
        }

        int mini = INT_MAX;

        
        for (int j = max(0, i - 3); j < i; j++) {

            int jumpCost = costs[i - 1] + (i - j) * (i - j);

            int totalCost = solve(j, costs, dp) + jumpCost;

            mini = min(mini, totalCost);
        }

        return dp[i] = mini;
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, -1);

        return solve(n, costs, dp);
    }
};
