class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> key_value;

        for (auto x : knowledge) {
            key_value[x[0]] = x[1];
        }

        string ans = "";
        int i = 0;

        while (i < s.size()) {

            if (s[i] == '(') {

                string temp = "";
                int j = i + 1;

                while (s[j] != ')') {
                    temp += s[j];
                    j++;
                }

                i = j + 1;

                auto it = key_value.find(temp);

                if (it == key_value.end()) {
                    ans += "?";
                }
                else {
                    ans += it->second;
                }

            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};