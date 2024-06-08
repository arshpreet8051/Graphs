#include<bits/stdc++.h>
using namespace std;

/*

    Note:
         - This poblem is extension of previous problem of Briges, So refer to it before.
*/ 
class Solution {
  public:
    void dfs(int node,int parent,int &timer,vector<int>&low,vector<int>&disc,vector<int>adj[],vector<int>&visited,vector<int>&ans){
        
        visited[node] = 1;
        
        low[node] = disc[node] = timer;
        timer++;
        
        int child = 0;
        
        for(auto nbr : adj[node]){
            
            if(nbr == parent)continue;
            
            if(visited[nbr]==0){
                
                
                // apply dfs
                dfs(nbr,node,timer,low,disc,adj,visited,ans);
                // 
                low[node] = min(low[node],low[nbr]);
                
                // check if Articulation point
                if(low[nbr]>=disc[node] and parent!=-1){
                    ans[node] = 1;
                }
                // increment child
                child++;
            }
            
            else{
                // Back Edge case
                low[node] = min(low[node],disc[nbr]);
            }
            
        }
        
        if(parent==-1 and child>1)ans[node] = 1;
        
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        // initialize the required data structures
        vector<int> ans(V);
        vector<int> low(V);
        vector<int> disc(V);
        vector<int> visited(V);
        int timer = 1;
        int parent = -1;
        
        // apply dfs
        for(int i = 0;i<V;i++){
            dfs(i,parent,timer,low,disc,adj,visited,ans);
        }
        
        vector<int> articulation_points;
        
        for(int i = 0;i<ans.size();i++){
            if(ans[i]==1){
                articulation_points.push_back(i);
            }
        }
        
        if(articulation_points.size()==0){
            articulation_points.push_back(-1);
        }
        
        return articulation_points;
       
    }
};