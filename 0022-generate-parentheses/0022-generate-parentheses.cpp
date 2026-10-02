class Solution {
public:
    void solve(vector<string>&ans , int n , int open , int close , string path){

        if( open == n && close == n){
            ans.push_back(path);
            return;
        }

        if(open < n){
            solve(ans , n,  open + 1, close , path + '(' );
        }
        if(open > close){
            solve(ans , n , open , close +1 , path + ')');
        }
 
    }
    vector<string> generateParenthesis(int n) {

        vector<string>ans;
        solve(ans , n  , 0 , 0 , "");
        return ans;
    }
};