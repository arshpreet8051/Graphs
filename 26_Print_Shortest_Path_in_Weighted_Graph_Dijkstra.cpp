#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        
        // mainting a memoization array - inorder to keep a track of node from where we have come from
        vector<int> parent(n+1);
        
        for(int i = 0;i<=n;i++){
            
            parent[i] = i;
            
        }
        
        // making adjancency list with weights
        vector<vector<int>>adj[n+1];
        
        for(auto it : edges){
            
            int u = it[0];
            int v = it[1];
            
            int w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        // using Priority queue to apply Dijkstra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        // Dist array to store min distances
        vector<int> dist(n+1,1e9);
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int weight = pq.top().first;
            
            pq.pop();
            
            for(auto it : adj[node]){
                
                int adjNode = it[0];
                int adjW = it[1];
                
                if(weight + adjW < dist[adjNode]){
                    dist[adjNode] = weight + adjW;
                    
                    // Game store parent node
                    parent[adjNode] = node;
                    
                    pq.push({dist[adjNode],adjNode});
                }
                
            }
            
        }
        
        // If destination is not visited - not possible
        if(parent[n]==n)return {-1};
        
        vector<int> ans;
        
        int it = n;
        
        // Backtrack usinf parent array
        while(it!=1){
            ans.push_back(it);
            it = parent[it];
        }
        
        ans.push_back(it);
        ans.push_back(dist[n]);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};