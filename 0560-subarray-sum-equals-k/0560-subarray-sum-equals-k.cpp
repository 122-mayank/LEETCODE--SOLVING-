class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int prefixSum = 0;
        unordered_map<int , int>mp;

        mp[0] = 1;

        int count = 0;

        for(int i = 0 ; i < nums.size() ;i++){

              prefixSum = prefixSum + nums[i];

              if(mp.find(mp[prefixSum - k]) != mp.end()){
                    count = count + mp[prefixSum - k];
              }
              mp[prefixSum]++;
        }

        return count;          
        
    }
};