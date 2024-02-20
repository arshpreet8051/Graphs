#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
/*
        Use Recursion for Depth first approach
        
        Requirements: 
                        -> Visited array
                        -> adjacency matrix
*/
class Solution {
  public:
    void dfs(int node,int v,vector<int>&ans,vector<int>&visited,vector<int> adj[]){
        
        if(node>v)return;
        
        visited[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!visited[it]){
                visited[node] = 1;
                dfs(it,v,ans,visited,adj);
            }
        }
        
        return;
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int>ans;
        
        dfs(0,V,ans,visited,adj);
        
        return ans;
    }
};