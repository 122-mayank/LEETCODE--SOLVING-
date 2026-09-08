class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        vector<int>prefixMaximum(nums.size());
        vector<int>prefixMinimum(nums.size());

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int ans = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++){
              maxi = max(maxi , nums[i]);
              prefixMaximum[i] = maxi;
        }

        for(int j = nums.size() - 1 ; j >= 0 ; j--){
             mini = min(mini , nums[j]);
             prefixMinimum[j] = mini;
        }

        for(int i = 0 ; i < nums.size() ; i++){
             
             int diff = prefixMaximum[i] - prefixMinimum[i];

             if(diff <= k){
                ans = min(ans , i);
             }

        }

        return ans == INT_MAX ? -1 : ans;

    }
};