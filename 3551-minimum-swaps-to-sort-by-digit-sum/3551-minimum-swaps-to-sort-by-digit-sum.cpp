class Solution {
public:
    int minSwaps(vector<int>& nums) {

       int size = nums.size();

       vector<pair<int,int>>arr;

       //store the sum with value
       for(int x : nums){

          int temp = x;
          int sum = 0;

          while(temp > 0){
             int rem = temp % 10;
             sum = sum + rem;
             temp = temp / 10;
          }

          arr.push_back({sum , x});

       }

       sort(arr.begin() , arr.end());

       unordered_map<int , int>pos;

       for(int i = 0 ; i < nums.size() ; i++){
             pos[nums[i]] = i;
       }

       int swaps = 0;

       for(int i = 0 ; i < arr.size() ; i++){ 
            
            auto temp = arr[i];

            int sum = temp.first;
            int val = temp.second;

            if(val == nums[i])
                continue;

            int correctIndex = pos[val];

            swap(nums[i] , nums[correctIndex]);

            pos[val] = i;
            pos[nums[correctIndex]] = correctIndex;

            swaps++;
                
       }

       return swaps;

    }
};