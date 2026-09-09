class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;

        for(int nextNode : adj[node]){
            if(!vis[nextNode]){
                dfs(nextNode, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int comp = 0;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                comp++;
                dfs(i, vis, adj);
            }
        }
        return comp;
    }
};
