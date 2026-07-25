class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            dp[i][j] = 2 + solve(s, i+1, j-1);
        } else {
            dp[i][j] = max(solve(s, i+1, j), solve(s, i, j-1));
        }
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(s, 0, n-1);
    }
};
