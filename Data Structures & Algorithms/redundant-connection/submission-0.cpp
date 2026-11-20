class dsu{
private:
    vector<int> parent, size;
public:
    dsu(int n){
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int node1, int node2){
        int par1 = findUPar(node1);
        int par2 = findUPar(node2);

        if(par1 == par2) return;

        if(size[par1] < size[par2]){
            parent[par1] = par2;
            size[par2] += size[par1];
        }else{
            parent[par2] = par1;
            size[par1] += size[par2];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        dsu ds(n + 1);

        for(int i = 0; i < n; i++){
            if(ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1])){
                return edges[i];
            }
            ds.unionBySize(edges[i][0], edges[i][1]);
        }
    }
};
