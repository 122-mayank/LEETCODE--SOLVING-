class Solution {
public:
    unordered_set<string> ans;
    int n;
    int minRemove = INT_MAX;

    void solve(string& s, string& temp, int idx,
               int open, int close, int removed) {

        if (idx == n) {

            if (open == close) {

                if (removed < minRemove) {
                    minRemove = removed;
                    ans.clear();
                    ans.insert(temp);
                }
                else if (removed == minRemove) {
                    ans.insert(temp);
                }
            }

            return;
        }

        // Character is '('
        if (s[idx] == '(') {

 
            temp.push_back('(');

            solve(s, temp, idx + 1,
                  open + 1, close, removed);

            temp.pop_back();


            solve(s, temp, idx + 1,
                  open, close, removed + 1);
        }


        else if (s[idx] == ')') {

            if (open > close) {

                temp.push_back(')');

                solve(s, temp, idx + 1,
                      open, close + 1, removed);

                temp.pop_back();
            }

            solve(s, temp, idx + 1,
                  open, close, removed + 1);
        }

        else {

            temp.push_back(s[idx]);

            solve(s, temp, idx + 1,
                  open, close, removed);

            temp.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        n = s.size();
        string temp = "";

        solve(s, temp, 0, 0, 0, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};