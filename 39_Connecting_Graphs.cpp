/*
You can remove one edge from anywhere and add that edge between any two vertices in one operation.

Find the minimum number of operations that will be required to make the graph connected.
*/
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
        
        if(parent[node]==node){
            return node;
        }
        
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    
    void union_by_size(int u, int v){
        
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);
        
        if(ulp_u==ulp_v)return;
        
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    
    int number_of_components(int n){
        
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
    int Solve(int n, vector<vector<int>>& edge) {
        
        disjoint_set ds = disjoint_set(n);
        int m = edge.size();
        
        int faltu_edges = 0;
        
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            
            if(ds.find_ultimate_parent(u)==ds.find_ultimate_parent(v)){
                faltu_edges++;
            }
            else{ds.union_by_size(u,v);}
        }
        
        int components = ds.number_of_components(n);
        
        if(components-1>faltu_edges)return -1;
        
        return (components-1);
        
    }
};