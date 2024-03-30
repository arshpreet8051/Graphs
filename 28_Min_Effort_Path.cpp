#include<iostream>
#include<vector>
#include<priority_queue>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        
        // we will use Dijkstra to find shortest path
        // we will also use priority queue as Min Heap
        // Instead of weights we will use (effort = | current cell height - new cell height|)
        
        int n = heights.size();
        int m = heights[0].size();
        
        int src_x = 0;
        int src_y = 0;
        
        int final_x = n-1;
        int final_y = m-1;
        
        int delta_x[4] = {-1,1,0,0};
        int delta_y[4] = {0,0,-1,1};
        
        // min heap
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
        
        // duplicate matrix to keep track of distances
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        pq.push({{0,0},0});
        
        while(!pq.empty()){
            
            int x = pq.top().first.first;
            int y = pq.top().first.second;
            int effort = pq.top().second;
            
            pq.pop();
            
            if(x==final_x and y==final_y){
                return effort;
            }
            
            for(int i = 0;i<4;i++){
                
                int new_x = x + delta_x[i];
                int new_y = y + delta_y[i];
                
                if( (new_x>=0 and new_x<n) and (new_y>=0 and new_y<m) and 
                (dist[new_x][new_y] > max(effort,abs(heights[x][y] - heights[new_x][new_y])))){
                    
                    dist[new_x][new_y] = max(effort,abs(heights[x][y] - heights[new_x][new_y]));
                    pq.push({{new_x,new_y},dist[new_x][new_y]});
                }
            }
        }
        
        return -1;
        
    }
};