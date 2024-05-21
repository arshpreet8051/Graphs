class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int maxRow = 0;
        int maxCol = 0;
        
        for(auto it : stones){
            
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
            
        }
        
        DisjointSet ds = DisjointSet(maxRow + maxCol + 1);
        
        unordered_map<int,int>mp;
        
        for(auto it : stones){
            
            int rowNo = it[0];
            int colNo = it[1] + maxRow + 1;
            
            ds.unionBySize(rowNo,colNo);
            mp[rowNo] = 1;
            mp[colNo] = 1;
        }
        
        int no_of_components = 0;
        
        for(auto it : mp){
            if(ds.findUltimateParent(it.first) == it.first){no_of_components++;}
        }
        
        return n - no_of_components;
    }
};