class Solution {
public:
    bool detect(int src, vector<int> adj[], vector<int> &vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(parent != it) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;  // No cycle detected
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;  // Quick check

        vector<int> vis(n, 0);
        vector<int> adj[n];

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if (detect(0, adj, vis)) {
            return false;  // Cycle detected
        }

        // Check if all nodes were visited
        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;  // Graph is not connected
        }

        return true;  // No cycle and all nodes are connected
    }
};
