class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int firstMin = -1;
        int lastMin = -1;

        int firstMax = -1;
        int lastMax = -1;

        for (int i = 0; i < n; i++) {

            if (nums[i] == mini) {
                if (firstMin == -1)
                    firstMin = i;

                lastMin = i;
            }

            if (nums[i] == maxi) {
                if (firstMax == -1)
                    firstMax = i;

                lastMax = i;
            }
        }

        // Convert 0-based index to number of deletions from front
        int frontMin = firstMin + 1;
        int frontMax = firstMax + 1;

        // Number of deletions from back
        int backMin = n - lastMin;
        int backMax = n - lastMax;

        int ans = INT_MAX;

        // Remove both from front
        ans = min(ans, max(frontMin, frontMax));

        // Remove both from back
        ans = min(ans, max(backMin, backMax));

        // Min from front, max from back
        ans = min(ans, frontMin + backMax);

        // Max from front, min from back
        ans = min(ans, frontMax + backMin);

        return ans;
    }
};