class disjoint_set{
    
    vector<int> parent,size;
    
    public:
    disjoint_set(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
        }
    }
    
    int find_ultimate_parent(int node){
        
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    
    void union_by_size(int u,int v){
        
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);
        
        if(ulp_u==ulp_v)return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
     }
     
     int number_of_provinces(int n){
         int ans = 0;
         for(int i = 0;i<n;i++){
             if(parent[i]==i){
                 ans++;
             }
         }
         
         return ans;
     }
    
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        disjoint_set ds = disjoint_set(V);
        
        for(int i = 0;i<adj.size();i++){
            for(int j = 0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    ds.union_by_size(i,j);
                }
            }
        }
        
        return ds.number_of_provinces(V);
        
    }
};