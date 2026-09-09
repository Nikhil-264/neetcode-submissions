class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preReq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(int i = 0; i < preReq.size(); i++){
            adj[preReq[i][1]].push_back(preReq[i][0]);
            indegree[preReq[i][0]]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        if(topo.size() != n) return {};
        return topo;
    }
};
