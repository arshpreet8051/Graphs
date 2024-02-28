#include<iostream>
#include<vector>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution
{
    private:
    void dfs(int node,vector<int>&visited,vector<int>adj[],stack<int>&st){
        
        visited[node] = 1;
        
        for(auto x : adj[node]){
            
            if(visited[x]==-1){
                dfs(x,visited,adj,st);
            }
            
        }
        
        st.push(node);
        
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    
	    stack<int> st;
	    vector<int>visited(n,-1);
	    
	    for(int i = 0;i<n;i++){
	        
	        if(visited[i]==-1){
	            dfs(i,visited,adj,st);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    
	    return ans;
	    
	}
};