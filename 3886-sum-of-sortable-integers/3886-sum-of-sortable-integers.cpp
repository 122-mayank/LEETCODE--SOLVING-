class Solution {
public:
    void computeLPS(vector<int>& LPS, vector<int>& pat, int M) {

        int length = 0;

        int i = 1;

        LPS[0] = 0;

        while (i < M) {

            if (pat[i] == pat[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = LPS[length - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    bool KMP(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();

        vector<int> LPS(M, 0);

        computeLPS(LPS, pat, M);

        int i = 0;
        int j = 0;

        while (i < N) {

            if (txt[i] == pat[j]) {
                i = i + 1;
                j = j + 1;
            }
            if (j == M) {
                return true;
            } else if (i < N && txt[i] != pat[j]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }

        return false;
    }

    bool isRotation(vector<int>& vec1, vector<int>& vec2) {
        vector<int> text = vec2;
        text.insert(end(text), begin(vec2), end(vec2));

        return KMP(vec1, text);
    }
    int sortableIntegers(vector<int>& nums) {

        int n = nums.size();

        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        int result = 0;

        for (int k = 1; k <= n; k++) {

            if (n % k != 0)
                continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {

                vector<int> vec1(begin(nums) + start, begin(nums) + start + k);
                vector<int> vec2(begin(sorted) + start,
                                 begin(sorted) + start + k);

                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result += k;
            }
        }

        return result;
    }
};