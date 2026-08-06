class Solution {
public:

    bool isPalindrome(string &s, int i, int j) {

        if (i >= j) {
            return true;
        }

        if (s[i] != s[j]) {
            return false;
        }

        return isPalindrome(s, i + 1, j - 1);
    }

    int solve(string &s, int start, int end) {

        if (start >= s.size()) {
            return 0;
        }

        int count = 0;

        for (int i = start; i <= end; i++) {

            if (isPalindrome(s, start, i)) {
                count++;
            }
        }

        return count + solve(s, start + 1, end);
    }

    int countSubstrings(string s) {
        return solve(s, 0, s.size() - 1);
    }
};