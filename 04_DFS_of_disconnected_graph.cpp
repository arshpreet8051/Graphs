#include<iostream>
#include<vector>
#include <map>
#include <unordered_map>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 

void dfs(int node,vector<int>&visited,unordered_map<int,vector<int>>&adj_list,vector<int>&temp){

    visited[node] = 1;
    temp.push_back(node);

    for(auto it : adj_list[node]){
        if(visited[it]==0){
            dfs(it,visited,adj_list,temp);
        }
    }
    return;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,vector<int>>adj_list;

    for(int i = 0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> visited(V,0);

    vector<vector<int>> ans;

    for(int i = 0;i<V;i++){

        if(visited[i]==0){
            vector<int> temp;
            dfs(i,visited,adj_list,temp);
            ans.push_back(temp);
        }
    }

    return ans;

}