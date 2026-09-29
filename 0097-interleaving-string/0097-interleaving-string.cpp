class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool solve(string&s1 , string& s2 , string& s3 , int i , int j , int k ){

        if(i >= s1.size() && j >= s2.size() && k >= s3.size()){
            return true;
        }

        bool option1 = false;
        bool option2 = false;

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        if (i < s1.size() && s1[i] == s3[k]) {
            option1 = solve(s1, s2, s3,
                            i + 1, j, k + 1);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            option2 = solve(s1, s2, s3,
                            i, j + 1, k + 1);
        }

        return dp[i][j][k] = option1 || option2;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int o = s3.size();

         if (m + n != o)
            return false;

        dp.assign(
            m + 1,
            vector<vector<int>>(
                n + 1,
                vector<int>(o + 1, -1)
            )
        );
        return solve(s1 , s2 , s3 , 0, 0 , 0);
 
    }
};