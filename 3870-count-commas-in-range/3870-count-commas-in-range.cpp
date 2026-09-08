class Solution {
public:
    int countCommas(int n) {
        if( n < 1000){
            return 0;
        }

        if(n >= 1000 && n < 100000){
            int diff = n - 1000;
            return diff + 1;
        }

        return 99001;
    }
};