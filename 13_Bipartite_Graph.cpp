#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
private:
    bool dfs(int node,int col,vector<int>&color,vector<int>adj[]){
        
        color[node] = col;
        
        for(auto x : adj[node]){
    
            if(color[x]==-1){if(dfs(x,!col,color,adj)==false){return false;}}
            
            else if(color[x]==col)return false;
            
        }
        
        return true;
        
    }
public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    
	    vector<int>color(n,-1);
	    
	    for(int i =0;i<n;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj)==false)return false;
	        }
	    }
	    
	    return true;
	}

};