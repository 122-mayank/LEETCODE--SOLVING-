class Solution {
public:
    int minMoves2(vector<int>& nums) {

            // apply the bruteforce approach
            int n = nums.size();
            long int mini = INT_MAX;

            for(int i = 0 ; i < n ; i++){
                  
                  long int sum = 0;
                  
                 for(int j = 0 ; j < n ; j++){
                       
                       long int diff = abs(nums[i] - nums[j]);
                       sum += diff; 
                 }

                mini = min(mini , sum);

            }
          return mini;
    }
};