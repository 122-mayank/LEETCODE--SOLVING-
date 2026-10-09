class Solution {
public:
    int minInsertions(string s) {
        
        int size = s.size();

        int i = 0;
        int count = 0;
        int result = 0;

        while( i < size){

            if(s[i] == '('){
                count = count + 1;
                i = i + 1;
            }else{

                if(count > 0){
                    count--;
                }else{
                    result = result + 1;    //adding a '('
                }

                if(i + 1 < size && s[i+1] == ')'){
                    i += 2;
                }else{
                    result = result + 1;
                    i = i + 1;
                }

            }

        }

        return result + (count * 2);

    }
};