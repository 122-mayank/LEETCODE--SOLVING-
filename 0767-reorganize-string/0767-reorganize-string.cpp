class Solution {
public:
    string reorganizeString(string s) {

        int size = s.size();

        unordered_map<char, int> mp;

        // Count frequency
        for(char ch : s) {
            mp[ch]++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for(auto it : mp) {
            maxFreq = max(maxFreq, it.second);
        }

        // If arrangement is impossible
        if(maxFreq > (size + 1) / 2) {
            return "";
        }

        // Max heap
        priority_queue<pair<int, char>> pq;

        // Push each distinct character only once
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string res = "";

        // Previous character that cannot be used immediately
        pair<int, char> prev = {0, '#'};

        while(!pq.empty()) {

            auto [freq, ch] = pq.top();
            pq.pop();

            res += ch;
            freq--;

            // Put previous character back into heap
            if(prev.first > 0) {
                pq.push(prev);
            }

            // Current character becomes previous
            prev = {freq, ch};
        }

        return res;
    }
};