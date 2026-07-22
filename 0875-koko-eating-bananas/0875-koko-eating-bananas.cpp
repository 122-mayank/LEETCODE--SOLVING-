class Solution {
public:
    long long findHours(vector<int>& piles, int expectedBananas) {

       long long int totalHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalHours =
                totalHours + (long long int)ceil((double)piles[i] / expectedBananas);
        }

        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        int low = 1;
        int high = maxi;

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long minHours = findHours(piles, mid);

            if (minHours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};