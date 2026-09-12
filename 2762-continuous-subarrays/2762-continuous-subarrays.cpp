class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {


        ///make the max heap and min heap
        int n = nums.size();

        priority_queue<pair<int, int>>maxHeap;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>minHeap;

        int left = 0;
        int right = 0;

        long long count = 0;

        while(right < n){

            maxHeap.push({nums[right] , right});
            minHeap.push({nums[right] , right});

            while(maxHeap.top().first - minHeap.top().first > 2){

                left = left + 1;

                while(!maxHeap.empty() && maxHeap.top().second < left){
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < left){
                     minHeap.pop();
                }


            }

            count += right - left + 1;
            right = right + 1;

        }

        return count;
        
    }
};