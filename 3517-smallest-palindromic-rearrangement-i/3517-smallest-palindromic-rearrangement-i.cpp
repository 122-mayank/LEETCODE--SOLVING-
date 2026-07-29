class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());

        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        string leftPart = "", rightPart = "";
        char middleChar = '\0';

        for (char c : s) {
            if (freqMap[c] > 0) {
                int count = freqMap[c];
                freqMap[c] = 0; // consume all occurrences

                // If odd count, one goes to middle
                if (count % 2 == 1) {
                    if (middleChar == '\0') {
                        middleChar = c;
                        count--; // use remaining even part
                    }
                }

                // Add half to left, half to right
                string half(count / 2, c);
                leftPart += half;
                rightPart = half + rightPart;
            }
        }

        string ans = leftPart;
        if (middleChar != '\0') ans += middleChar;
        ans += rightPart;

        return ans;
    }
};
