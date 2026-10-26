class Solution {
public:
    int m , n;

    void dfs(long long &sum , vector<vector<int>>&grid , int i ,int j ,
    vector<vector<bool>>&visited){

        visited[i][j] = true;
        sum = sum + grid[i][j];
         
        if(i - 1 >= 0 && !visited[i-1][j] && grid[i-1][j] != 0){
            dfs(sum , grid , i - 1 , j , visited);
        }

        if(i + 1 < m && !visited[i+1][j] && grid[i+1][j] != 0){
            dfs(sum , grid , i + 1 , j , visited);
        }

        if(j - 1 >= 0 && !visited[i][j-1] && grid[i][j-1] != 0){
            dfs(sum , grid , i , j - 1 , visited);
        }

        if(j + 1 < n && !visited[i][j+1] && grid[i][j+1] != 0){
            dfs(sum , grid , i , j + 1 , visited);
        }

    }

    int countIslands(vector<vector<int>>& grid, int k) {
        
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>>visited(m , vector<bool>( n , false));
        int res = 0;

         for(int i = 0 ; i < m ; i++){
             for(int j = 0 ; j < n ; j++){
                 if(!visited[i][j] && grid[i][j] != 0){
                      long long int sum = 0;

                      dfs(sum , grid , i , j , visited);

                     if(sum % k == 0) res++;
                 }
             }
         }
         return res;

    }
};