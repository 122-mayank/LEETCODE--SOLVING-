class Solution {
public:
    bool checkDivisibility(int n) {

        int sum = 0;
        int num_sum = n;

        while(num_sum != 0){
            sum += ( num_sum % 10);
            num_sum = num_sum / 10;
        }

        int prod_sum = n;
        int prod = 1;
        while(prod_sum != 0){
             prod = prod * (prod_sum % 10);
             prod_sum = prod_sum /10;
        }

        int totalSum = prod + sum;
        cout << totalSum << endl;

        if(n % totalSum == 0){
             return true;
        }

        return false;

        
    }
};