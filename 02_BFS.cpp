#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
// Requirements :
/*                  
                    -> Ajdacency list
                    -> Queue
                    -> Visited array
*/

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        vector<int> visited(V,0);
        queue<int> q;
        
        q.push(0);
        visited[0] = 1;
        
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto x : adj[node]){
                
                if(visited[x]==0){
                    visited[x]=1;
                    q.push(x);
                }
            }
        }
        
        return ans;
}