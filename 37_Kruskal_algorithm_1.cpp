#include<iostream>
#include<priority_queue>

using namespace std;

/*

    Note : 

           - This is Kruskal Algo approach to find min weight of MST
           - Uses Disjoint Set - Union by size
           - Uses Priority Queue to sort weights
*/




class disjoint_set{
    
    vector<int> size,parent;
    
    public:
    disjoint_set(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        
        for(int i = 0;i<n+1;i++){
            parent[i] = i;
        }
    }
    
    int find_ultimate_parent(int node){
        
        // base case
        
        if(parent[node]==node){
            return node;
        }
        
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    
    void union_by_size(int u,int v){
        
        // already belong to same component
        int ulp_u = find_ultimate_parent(u);
        int ulp_v =find_ultimate_parent(v);
        
        if( ulp_u == ulp_v){
            return;
        }
        
        // connent smaller size component to the larger size one
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        
        return;   
    }
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int ans = 0;
        
        for(int i = 0;i<V;i++){
            
            for(auto it : adj[i]){
                
                int v = it[0];
                int wt = it[1];
                int u = i;
                
                pq.push({wt,{u,v}});
                //pq.push({wt,{v,u]}});
            }

        }
        
        disjoint_set ds= disjoint_set(V);
        
        while(!pq.empty()){
            
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            
            pq.pop();
            
            // have same ultimate parent can form loop
            if(ds.find_ultimate_parent(u) == ds.find_ultimate_parent(v)){
                continue;
            }
            
            ans += wt;
            ds.union_by_size(u,v);
            
        }
        
        return ans;
        
    }
};