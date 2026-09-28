class Solution {
public:
    int maxDepth(string s) {

        int maxi = 0;
        int val = 0;
        for(int i = 0 ; i < s.size() ; i++){
              if(s[i] == '('){
                 val = val + 1;
              }
              else if(s[i] == ')'){
                 maxi = max(maxi , val);
                 val = val - 1;
              }
        }

        return maxi;
    }
};