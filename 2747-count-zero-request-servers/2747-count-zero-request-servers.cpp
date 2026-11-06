
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> active(n + 1, 0);
        vector<int> ans(q);

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (auto& query : sortedQueries) {

            int time = query.first;
            int idx = query.second;

            int start = time - x;

            // Add logs up to current query time
            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int server = logs[right][0];

                if (active[server] == 0) {
                    activeServers++;
                }

                active[server]++;
                right++;
            }

            // Remove logs outside the interval
            while (left < right &&
                   logs[left][1] < start) {

                int server = logs[left][0];

                active[server]--;

                if (active[server] == 0) {
                    activeServers--;
                }

                left++;
            }

            ans[idx] = n - activeServers;
        }

        return ans;
    }
};
