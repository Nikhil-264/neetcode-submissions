class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[k] = 0;
        queue<pair<int, int>> q;
        q.push({k, 0});

        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();

            for(auto it : adj[node.first]){
                int nextNode = it.first;

                if(node.second + it.second < dist[nextNode]){
                    dist[nextNode] = node.second + it.second;
                    q.push({nextNode, dist[nextNode]});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
