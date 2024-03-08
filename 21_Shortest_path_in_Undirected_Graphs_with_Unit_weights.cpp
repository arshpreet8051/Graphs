#include<queue>
#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        
        for(auto x : edges){
            
            int u = x[0];
            int v = x[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<int>dist(N,1e9);
        dist[src]=0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto x : adj[node]){
                if(dist[x] > 1 + dist[node]){
                    dist[x] = 1 + dist[node];
                    q.push(x);
                }
            }
        }
        
        vector<int>ans(N,-1);
        for(int i = 0;i<N;i++){
            if(dist[i]!=1e9){
                ans[i]=dist[i];
            }
        }
        
        return ans;
    }
};