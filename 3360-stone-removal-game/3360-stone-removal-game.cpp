class Solution {
public:
    bool canAliceWin(int n) {

        int stones = 10;
        bool flag = true;

        while(n >= stones){
            n = n - stones;
            flag = !flag;
            stones--;
        }

        return !flag;
        
    }
};