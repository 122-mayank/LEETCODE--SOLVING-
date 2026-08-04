class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

     if(nums1.size() > nums2.size()){
           return findMedianSortedArrays( nums2  ,nums1);
     }   
    

      int m  = nums1.size();
      int n = nums2.size();

      int left  = 0;
      int right = m;

      while(left <= right){
              
              int midA =  (left + right)/2;
              int midB = (m + n + 1)/  2 - midA;

              int maxLeftA = (midA== 0)? INT_MIN : nums1[midA-1];
              int minRightA = (midA == m) ? INT_MAX : nums1[midA];

              int maxLeftB = (midB == 0)?INT_MIN : nums2[midB-1];
              int minRightB = (midB == n)? INT_MAX: nums2[midB];

              if(maxLeftA <= minRightB && maxLeftB <= minRightA){
                 if((m+n) %  2== 0){
                    return( max(maxLeftA , maxLeftB) + min(minRightA , minRightB))/2.0;
                 }
                 else{
                    return max(maxLeftA , maxLeftB);
                 }
              }
              else if(maxLeftA >  minRightB){
                  right = midA-1;
              }
              else{
                left = midA+1;
              }


      }

      return 0.0;



    }
};