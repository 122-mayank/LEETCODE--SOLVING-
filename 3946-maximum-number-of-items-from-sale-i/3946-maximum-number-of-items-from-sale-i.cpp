class Solution {
public:
    int memo[1001][1501];
    int solve(int n , int budget , int min_price , vector<vector<int>>& items , vector<int>&copies){

        if( n == 0){
            return budget / min_price;
        }

        if(memo[n][budget] != -1) return memo[n][budget];

        int take = 0;
        int skip = 0;
        int price = items[n-1][1];

        if(price <= budget){
            take = 1 + copies[n-1] + solve(n - 1 , budget - price , min_price , items , copies);
        }

        skip = solve(n - 1 , budget , min_price , items , copies);

        return memo[n][budget] = max(skip , take);

    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        int min_price = INT_MAX;

        vector<int>copies(n , 0);

        for(int i = 0 ; i < n ; i++){

            min_price = min(min_price , items[i][1]);
            int copy = 0;

            for(int j = 0 ; j < n ; j++){

                if( i == j) continue;
                if(items[j][0] % items[i][0] == 0){
                    copy++;
                }
            }

            copies[i] = copy;
        }

        memset(memo , -1 , sizeof(memo));

        return solve(n , budget , min_price , items,copies);

    }
};