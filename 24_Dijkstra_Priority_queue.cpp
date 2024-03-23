#include<iostream>
#include<vector>
#include<queue>

//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Similar to BFS approach using Priority Queue
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(V,1e9);
        
        // Distance from source to source is 0
        dist[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            
            int len = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]){
                
                // note here it is a vector
                
                int adjNode = it[0];
                int adjDis = it[1];
                
                if(len + adjDis < dist[adjNode]){
                    
                    dist[adjNode] = len + adjDis;
                    
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        return dist;
        
    }
};