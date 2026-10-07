class Solution {
public:
    int minAddToMakeValid(string s) {

        stack<char>st;
        int mini = 0;

        for(int i = 0 ; i < s.size() ; i++){

            if(s[i] == '('){
                st.push(s[i]);
            }

            else {

                if(st.empty()){
                    mini = mini + 1;
                }
                else{
                    st.pop();
                }
            }

        }

        if(st.empty()){
             return mini;
        }

        return st.size() + mini;


        
    }
};