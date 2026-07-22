class Solution {
public:
    vector<vector<int>> dp;

    bool solve(vector<int>& nums, int index, int currentSum, int target) {
        // Success base case
        if (currentSum == target)
            return true;

        // Failure base cases
        if (index >= nums.size() || currentSum > target)
            return false;

        if (dp[index][currentSum] != -1)
            return dp[index][currentSum];

        // Include element
        if (solve(nums, index + 1, currentSum + nums[index], target))
            return dp[index][currentSum] = true;

        // Exclude element
        if (solve(nums, index + 1, currentSum, target))
            return dp[index][currentSum] = true;

        return dp[index][currentSum] = false;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        int target = total / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, 0, 0, target);
    }
};
