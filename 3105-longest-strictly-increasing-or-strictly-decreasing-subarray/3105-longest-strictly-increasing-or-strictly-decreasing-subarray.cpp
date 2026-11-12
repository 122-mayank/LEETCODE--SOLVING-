class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int size = nums.size();

        int ans = 1;

        for(int i = 0 ; i < size ; i++){

            //check the strictly increasing
            int maxi = nums[i];
            int max_count = 1;

            for(int j = i  + 1 ; j < size ; j++){
                 if(maxi < nums[j]){
                    max_count++;
                    maxi = nums[j];
                 }
                 else{
                    break;
                 }
            }


            //check the strictly decreasing
            int mini = nums[i];
            int mini_count = 1;

            for(int j = i  + 1 ; j < size ; j++){
                 if(mini > nums[j]){
                    mini_count++;
                    mini = nums[j];
                 }
                 else{
                    break;
                 }
            }
            ans = max({ans , mini_count , max_count});
        }
        return ans;        
    }
};