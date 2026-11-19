
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int size = nums.size();

        sort(nums.begin(), nums.end());

        int maxi_elem = nums[size - 1];

        int a = maxi_elem - nums[2];

        int b = nums[size - 2] - nums[1];

        int c = nums[size - 3] - nums[0];

        return min({a, b, c});
    }
};
