class Solution {
public:
    bool checkValidString(string s) {

        int size = s.size();

        vector<vector<bool>>t( size + 1, vector<bool>(size + 1 , false));

        t[size][0] = true;
        for(int i = size - 1 ; i >= 0 ; i--){
            for(int open = 0 ; open <= size ; open++){

                bool isValid = false;

                if(s[i] == '*'){
                    isValid |= t[i+1][open+1];
                    isValid |= t[i+1][open];

                    if(open > 0){
                        isValid |= t[i+1][open-1];
                    }
                }else if(s[i] == '('){
                    isValid |= t[i+1][open+1];
                }else if(open > 0){
                    isValid |= t[i+1][open-1];
                }

                 t[i][open] = isValid;
                
            }
           
        }

        return t[0][0];
    }
};