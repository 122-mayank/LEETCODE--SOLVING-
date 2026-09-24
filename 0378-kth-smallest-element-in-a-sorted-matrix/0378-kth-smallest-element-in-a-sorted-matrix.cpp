class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int m = matrix.size();
        int n = matrix[0].size();

        //make the min heap
        priority_queue<pair<int , pair<int , int>>,
                       vector<pair<int , pair<int,int>>>,
                       greater<pair<int , pair<int , int>>>>pq;
        //put the first row of every element
        for(int i = 0 ; i < m ; i++){
             pq.push({matrix[i][0],{i , 0}});
        }

        while(k--){

            auto top = pq.top();
            pq.pop();

            int value = top.first;
            int row = top.second.first;
            int col = top.second.second;

            if(k == 0)
               return value;
            
            if(col + 1 < n){
                  pq.push({matrix[row][col+1], { row , col + 1}});
            }

        }

        return -1;
        
    }
};