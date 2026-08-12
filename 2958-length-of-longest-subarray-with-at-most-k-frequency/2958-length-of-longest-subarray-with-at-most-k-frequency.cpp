class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int left = 0;
        int maxi = 0;

        for (int right = 0; right < nums.size(); right++) {

            mp[nums[right]]++;

            // Window becomes invalid
            while (mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }

            // Current window is valid
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};