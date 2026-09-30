class Solution {
public:
    vector<vector<int>>dp;
    int solve(string&word1 , string&word2 , int i , int j){
            
            if(i >= word1.size()){
                return word2.size() - j;
            }

            if(j >= word2.size()){
                 return word1.size() - i;
            }
            
            if(dp[i][j] != -1){
                return dp[i][j];
            }

            if(word1[i] == word2[j]){
                 return dp[i][j] = solve(word1 , word2 , i + 1 , j + 1);
            }

            int insert = 1 + solve(word1 , word2 , i , j + 1);

            int delet = 1 + solve(word1 , word2 , i + 1 , j);

            int replace = 1 + solve(word1 , word2 , i + 1 , j + 1);

            return dp[i][j] = min({insert , delet , replace});

    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size() + 1 , vector<int>(word2.size() + 1, -1));
        return solve(word1 , word2 , 0 , 0);
    }
}; 