#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

/*

    - Use Khan's Algo
    - Similar logic to Find Topological Sort using BFS
*/
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    unordered_map<int,vector<int>>adj;
	    
	    for(auto x : prerequisites){
	        
	        int u = x.first;
	        int v = x.second;
	        
	        // to coomplete u first complete v
	        adj[v].push_back(u);
	    }
	    
	    vector<int>indegree(N,0);
	    
	    for(int i = 0;i<N;i++){
	        
	        for(auto x : adj[i]){
	            
	            indegree[x]++;
	        }
	        
	    }
	    
	    queue<int>q;
	    
	    for(int i = 0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    int cnt = 0;
	    
	    while(!q.empty()){
	        
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto x : adj[node]){
	            indegree[x]--;
	            if(indegree[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    
	    return cnt==N;
	}
};