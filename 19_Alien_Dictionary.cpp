#include<iostream>
#include<vector>
#include<stack>

//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution{
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
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int>adj[K];
        
        for(int i = 0;i<N-1;i++){
            
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.size(),s2.size());
            
            for(int ptr = 0;ptr<len;ptr++){
                
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
            
        }
        
        vector<int> topo = topoSort(K,adj);
        
        string ans = "";
        
        for(auto it : topo){
            ans+=it+'a';
        }
        
        return ans;
    }
};