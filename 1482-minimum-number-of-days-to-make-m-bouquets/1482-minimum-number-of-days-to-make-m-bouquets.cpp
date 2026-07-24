class Solution {
public:
    int possible(vector<int>&bloom , int day, int m ,int k){

        int count = 0;
        int flowers = 0;

        for(int  i = 0 ; i < bloom.size() ; i++){
             if(bloom[i] <= day){
                count = count + 1;
             }
             else{
                flowers += (count / k);
                count = 0;
             }
        }

        flowers += (count / k);
        if(flowers >= m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int mini = *min_element(bloomDay.begin() , bloomDay.end());
        int maxi = *max_element(bloomDay.begin() , bloomDay.end());

        int low = mini;
        int high = maxi;

        int ans = -1;

        while(low <= high){
             
             int mid = low + ( high - low ) / 2;

             if(possible(bloomDay , mid , m ,k)){
                ans = mid;
                high = mid - 1;
             }
             else{
                low = mid + 1;
             }
        }

        return ans;
        
    }
};