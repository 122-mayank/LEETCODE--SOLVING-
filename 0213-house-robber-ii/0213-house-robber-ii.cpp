class Solution {
public:
    int solve(vector<int>&nums , int idx , int size , vector<int>&dp){

        if(idx > size){
             return 0;
        }

        if(dp[idx] != -1){
             return dp[idx];
        }

        int steal = nums[idx] + solve(nums , idx + 2 , size , dp);
        int skip = solve(nums , idx + 1, size , dp);

        return dp[idx] = max(steal , skip);

    }
     
    int rob(vector<int>& nums) {

        //recursion + memoization
        int size = nums.size();

        if(size == 1){
             return nums[0];
        }

        if( size == 2){
             return max(nums[0] , nums[1]);
        }

        vector<int>dp(size + 1, - 1);

         int take_oth_house = solve(nums , 0 , size - 2 , dp);

         dp.assign(size+ 1 , -1);

         int take_1th_house = solve(nums ,1 , size - 1 , dp);

         int ans = max(take_oth_house , take_1th_house);

         return ans;
    }
};