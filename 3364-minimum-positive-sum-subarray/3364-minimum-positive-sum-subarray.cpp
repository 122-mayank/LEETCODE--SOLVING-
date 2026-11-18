
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int mini = INT_MAX;

        for(int k = l; k <= r; k++) {

            int sum = 0;

            // First window of size k
            for(int i = 0; i < k; i++) {
                sum += nums[i];
            }

            if(sum > 0) {
                mini = min(mini, sum);
            }

            // Slide the window
            for(int i = k; i < n; i++) {

                sum += nums[i];
                sum -= nums[i - k];

                if(sum > 0) {
                    mini = min(mini, sum);
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};
