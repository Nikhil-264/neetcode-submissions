class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int parent){
        vis[node] = 1;

        for(int nextNode : adj[node]){
            if(parent != nextNode){
                if(vis[nextNode]) return false;
                else dfs(nextNode, vis, adj, node);
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // dfs
        vector<int> vis(n, 0);
        int comp = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                comp++;
                bool track = dfs(i, vis, adj, -1);
                if(!track) return false;
            }
        }
        if(comp > 1) return false;
        return true;
    }
};
