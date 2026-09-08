class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        //bruteforce 
        int ans = INT_MAX;
        for(int i = 0 ; i  < nums.size() ; i++){
              int maxi = INT_MIN;
              int mini = INT_MAX;
              //find maximum
              for(int j = 0 ; j <= i ; j++){
                maxi = max(nums[j] , maxi);
              }
              //find minimum
              for(int k = i ; k < nums.size() ; k++){
                mini = min(nums[k] , mini);
              }
              int diff = maxi - mini;

              if(diff <= k){
                  ans = min(ans , i);
              }

        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};