#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
#include<unordered_map>
bool dfs(int node,vector<int>&visited,vector<int>&path_visited,unordered_map<int,vector<int>>&adj_list){

  visited[node] = 1;
  path_visited[node] = 1;

  for(auto x : adj_list[node]){
    
    if(visited[x]==-1){
      if(dfs(x,visited,path_visited,adj_list)==true){return true;}
    }

     else if(path_visited[x]==1){return true;}

  }

  // backtracking
  // the only different step from detect cycle in undirected graph
  path_visited[node] = 0;
  return false;

}
bool isCyclic(vector<vector<int>>& edges, int n, int e)
{
	// Write your code here
	 unordered_map<int,vector<int>>adj_list;

  for(auto x : edges){

	  int u = x[0];
	  int v = x[1];

   	 adj_list[u].push_back(v);

  }

  vector<int>visited(n,-1);
  vector<int>path_visited(n,-1);

  for(int i = 0;i<n;i++){

    if(visited[i]==-1){
      if(dfs(i,visited,path_visited,adj_list)==true){
        return 1;
      }
    }
  }

  return 0;
}
