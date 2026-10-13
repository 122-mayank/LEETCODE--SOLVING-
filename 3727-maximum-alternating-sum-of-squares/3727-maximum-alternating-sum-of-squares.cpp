class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {


        //change every number to positive
        for(int i = 0 ; i < nums.size() ; i++){
             nums[i] = abs(nums[i]);
        }

        sort(nums.begin() , nums.end());

        int i = 0;
        int j = nums.size() - 1;

        long long int result = 0;

        while( i <= j){

            if( i == j){
                result = result + (nums[j] * nums[j]);
            }
            else{
                result = result + (nums[j] * nums[j]) - (nums[i] * nums[i]);
            }    
            j--;
            i++;

        }

        return result;
    }
};