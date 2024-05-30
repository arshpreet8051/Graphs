/*

    Strongly connected components

    A strongly connected component is the component of a directed graph
    that has a path from every vertex to every other vertex in that component.
    It can only be used in a directed graph.


    Link - https://www.geeksforgeeks.org/strongly-connected-components/


*/


#include<bits/stdc++.h>
using namespace std;
 
class Solution
{
    
    private:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,stack<int>&st){
        
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        
        // storing node in stack in finishing order
        st.push(node);
        
    }
    
    private: void dfs_2(int node,vector<vector<int>>&adj_transpose,vector<int>&visited){
        
        visited[node] = 1;
        
        for(auto it : adj_transpose[node]){
            if(!visited[it]){
                dfs_2(it,adj_transpose,visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        // visited array
        vector<int> visited(V,0);
        
        // stack to store nodes in finishing time order
        stack<int> st;
        
        // step - 1 -> Apply DFS on the graph and store nodes in order of finishing time
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        
        // step - 2 -> reverse the graph - TRANSPOSE
        
        // another adjacency list for reversed graph
        vector<vector<int>>adj_transpose(V);
        
        for(int i = 0;i<V;i++){
            visited[i] = 0; // converting to '0' so that we can use it again
            
            for(auto it : adj[i]){
                adj_transpose[it].push_back(i);
            }
        }
        
        // step - 3 -> apply DFS on reversed graph and no of times dfs applied = no of strongly connected components
        
        int scc = 0;
        
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                scc++;
                dfs_2(node,adj_transpose,visited);
            }
            
        }
        
        return scc;
        
    }
};