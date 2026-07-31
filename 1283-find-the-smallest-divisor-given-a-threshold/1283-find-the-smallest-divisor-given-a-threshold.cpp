class Solution {
public:
    int validSum(int divisor , vector<int>&nums){

            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                sum = sum + (int)ceil((double)nums[j] / divisor);
            }

            return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int mini = INT_MAX;

        while(low <= high){

            int mid = low + (high - low ) / 2;
            int minSum = validSum(mid , nums);

            if(minSum <= threshold){
                  mini = mid;
                  high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }

        return mini;
    }
};