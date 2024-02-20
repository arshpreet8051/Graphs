#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;
#define or |
#define and &
/*
    We have to calculate isolated structures in a graph - provinces

    Algorithm:

                -> Maintain a visited array and mark every node as 0
                -> Our main goal is to visit every node
                -> The no of times we will apply BFS/ DFS to visit all nodes is the no of provinces

*/
class Solution {
  public:
    void dfs(int node,vector<int>&visited,unordered_map<int,vector<int>>&adj_list){
        
        visited[node]=1;
        
        for(auto it : adj_list[node]){
            
            if(visited[it]==0){
                dfs(it,visited,adj_list);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // create adjacency list
        
        unordered_map<int,vector<int>>adj_list;
        
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(adj[i][j]){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(V,0);
        
        int ans = 0;
        
        for(int i = 0;i<V;i++){
            
            if(visited[i]==0){
                dfs(i,visited,adj_list);
                ans++;
            }
        }
        
        return ans;
    }
};