class Solution {
public:
    int t[101][101];
    bool solve(string s , int open , int idx){

       if(idx >= s.size()){
          return open == 0;
       }

       if(t[idx][open] != -1){
         return t[idx][open];
       }

       bool isValid = false;

       if(s[idx] == '*'){

           isValid |= solve(s , open + 1 , idx + 1);
           isValid |= solve(s , open , idx + 1);
           if(open > 0)
               isValid |= solve(s , open - 1 , idx + 1);
          
       }

       else if(s[idx] == '('){
           isValid |= solve(s , open + 1 , idx + 1);
       }
       else if(open > 0){
          isValid |= solve(s , open - 1 , idx + 1); 
       }

       return t[idx][open] = isValid;

    }
    bool checkValidString(string s) {
        int size = s.size();
        memset(t , -1 , sizeof(t));
        return solve(s , 0 , 0);
    }
};