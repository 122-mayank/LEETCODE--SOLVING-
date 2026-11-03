class Solution {
public:
    int minMoves(vector<int>& nums) {

        int mini = *min_element(nums.begin(), nums.end());

        long long minimumMoves = 0;

        for(int i = 0; i < nums.size(); i++) {
            minimumMoves += (long long)nums[i] - mini;
        }

        return minimumMoves;
    }
};