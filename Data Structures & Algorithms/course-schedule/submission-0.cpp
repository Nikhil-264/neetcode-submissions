class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preReq) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < preReq.size(); i++){
            adj[preReq[i][1]].push_back(preReq[i][0]);
            indegree[preReq[i][0]]++;
        }


        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

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

        if(topo.size() == numCourses) return true;
        return false;
    }
};
