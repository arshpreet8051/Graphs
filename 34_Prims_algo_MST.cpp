#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    // adjacency list
    vector<pair<int,int>>adj[n+1];
    
    for(auto it : g){
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v,wt});
        adj[v].push_back({u, wt});
    }

    // answer vector
    vector<pair<pair<int, int>, int>> ans;
     // visited array
    vector<bool>vis(n+1,false);

    // priority queue
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;

    // {{weight,node},parent};

    // first node -> no parent -> so -1
    pq.push({{0,1},-1});

    while(!pq.empty()){

        int wt = pq.top().first.first;
        int node = pq.top().first.second;
        int parent = pq.top().second;

        pq.pop();

        if(vis[node]){continue;}

        vis[node] = true;

        if(parent!=-1){ans.push_back({{node,parent},wt});}

        for(auto it : adj[node]){
            int adj_node = it.first;
            int adj_wt = it.second;

            if(vis[adj_node]==false){pq.push({{adj_wt,adj_node},node});}
        }
    }
    return ans;
}

//----------------------------------------------------------------------------------------------------------------------------------

// Note - If only min weight of paths is required 

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // visited array
        vector<int>vis(V,0);
        //vis[0] = 1;
        
        // priority queue to apply greedy - Prims algo
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,0});
        
        int ans = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int wt = pq.top().first;
            
            pq.pop();
            
             if(vis[node]){continue;}
             vis[node] = 1;
             ans += wt;
            
            for(auto it : adj[node]){
                int adj_node = it[0];
                int adj_wt = it[1];
                
                
                if(vis[adj_node]==0){pq.push({adj_wt,adj_node});}
            }
            
        }
        return ans;
    }
};