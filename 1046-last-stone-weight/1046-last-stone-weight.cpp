class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // make the priority queue - max heap
        priority_queue<int> pq;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() > 1) {

            int value = pq.top();
            pq.pop();

            int value2 = pq.top();
            pq.pop();

            pq.push(value - value2);
        }
        int ans = pq.top();
        pq.pop();

        return ans;
    }
};