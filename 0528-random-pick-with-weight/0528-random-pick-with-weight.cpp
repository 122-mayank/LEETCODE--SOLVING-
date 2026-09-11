class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int>& w) {
        nums = w;
    }
    
    int pickIndex() {
        int total = 0;
        
        for (int x : nums) {
            total += x;
        }
        
        int target = rand() % total + 1;
        
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (target <= sum) {
                return i;
            }
        }
        
        return -1;
    }
};