class Solution {
public:
    bool checkString(string s) {

        int size = s.size();

        int a_index = -1 , b_index = -1;

        for(int i = size - 1 ; i >= 0 ; i--){

            if(s[i] == 'b'){
               b_index = i;
            }
            else{
                a_index = i;
            }

            if(a_index != -1 && b_index != -1 && (a_index > b_index)) return false;
        }

        return true;
        
    }
};