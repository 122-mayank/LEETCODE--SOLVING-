class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // Adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight : flights) {

            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }

        // {cost, node, flightsUsed}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // distance[node][flightsUsed]
        vector<vector<int>> distance(
            n,
            vector<int>(k + 2, INT_MAX)
        );

        distance[src][0] = 0;

        pq.push({0, src, 0});

        while(!pq.empty()) {

            auto [cost, node, flightsUsed] = pq.top();
            pq.pop();

            // Destination reached
            if(node == dst)
                return cost;

            // At most k + 1 flights
            if(flightsUsed == k + 1)
                continue;

            for(auto [neighbor, price] : adj[node]) {

                int newCost = cost + price;
                int newFlights = flightsUsed + 1;

                if(newCost < distance[neighbor][newFlights]) {

                    distance[neighbor][newFlights] = newCost;

                    pq.push({
                        newCost,
                        neighbor,
                        newFlights
                    });
                }
            }
        }

        return -1;
    }
};