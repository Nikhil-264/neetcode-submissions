class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.push({0, 0, src});
        vector<int> minStops(n, INT_MAX);

        while(!pq.empty()){
            auto [price, stops, node] = pq.top();
            pq.pop();

            if(stops >= minStops[node] or stops > k + 1) continue;
            minStops[node] = stops;

            if(node == dst){
                return price;
            }

            for(auto it : adj[node]){
                pq.push({price + it.second, stops + 1, it.first});
            }
        }
        return -1;
    }
};
