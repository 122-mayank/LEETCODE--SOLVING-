class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>ansArray;

        for(int i = 0 ; i < m ; i++){
             for(int j = 0 ; j < n ; j++){
                  ansArray.push_back(matrix[i][j]);
             }
        }

        sort(ansArray.begin() , ansArray.end());

        int ans = 0;

        for(int i = 0 ; i < ansArray.size() ; i++){
                if( i == k - 1){
                     ans = ansArray[i];
                     break;
                }
        }
        return ans;
    }
};