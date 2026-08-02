class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int low, int high) {
        if (low > high) return 0;
        if (dp[low][high] != -1) return dp[low][high];

        int option1 = piles[low] + 
            min(solve(piles, low + 2, high), solve(piles, low + 1, high - 1));
        int option2 = piles[high] + 
            min(solve(piles, low, high - 2), solve(piles, low + 1, high - 1));

        return dp[low][high] = max(option1, option2);
    }

    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        dp.assign(n, vector<int>(n, -1));

        int sum_A = solve(piles, 0, n - 1);

        int totalSum = 0;
        for (int i : piles) totalSum += i;

        int sum_B = totalSum - sum_A;

        return sum_A >= sum_B;
    }
};
