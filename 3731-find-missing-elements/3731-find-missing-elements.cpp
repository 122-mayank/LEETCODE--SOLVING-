class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());

        int k = 0;
        vector<int>ans;

        unordered_set<int>st;

        for(int i = 0 ; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        for(int i = mini ; i <= maxi ; i++){
             if(st.find(i) == st.end()){
                ans.push_back(i);
             }
        }     
        return ans;
    }
};