class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int size = nums.size();
        int maxi = 1;

        unordered_set<int>st;

        for(int i = 0 ; i < size ; i++){
              if(nums[i] % k == 0){
                st.insert(nums[i]);
                int div = nums[i] / k;
                maxi = max(maxi , div);
              }
        }

        cout << maxi << endl;

        for(int i = 1 ; i <= maxi ; i++){
              int multiple = i * k;

              if(st.find(multiple) == st.end()){
                  return multiple;
              }
        }

        return (maxi + 1) * k;


    }
};