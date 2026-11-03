class Solution {
public:
    int minMoves(vector<int>& nums) {

        //find the maximum
        int n = nums.size();

        int maxi = INT_MIN;

        for(int i = 0 ; i < n ; i++){
             maxi = max(nums[i], maxi);
        }

        int sum = 0;

        for(int i = 0 ; i < n ; i++){
             int diff = abs(maxi - nums[i]);
             sum = sum + diff;
        }

        return sum;
        
    }
};