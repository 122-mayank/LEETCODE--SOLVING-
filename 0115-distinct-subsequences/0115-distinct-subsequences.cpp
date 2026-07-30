class Solution {
public:
    vector<vector<int>>dp;
    int s_size , t_size;
    int solve(string& s, string& t, int i, int j) {

        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }    

        int ways = solve(s, t, i + 1, j);

        if (s[i] == t[j]) {
            ways += solve(s, t, i + 1, j + 1);
        }

        return dp[i][j] = ways;
    }

    int numDistinct(string s, string t) { 
        s_size = s.size();
        t_size = t.size();
        dp.resize(s_size, vector<int>(t_size , -1));
        return solve(s, t, 0, 0); 
    }
};
