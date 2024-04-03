#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int src, int end) {
        // Use BFS to traverse 
        // the product after multiplication will be treated as adjacent node
        
        // max possible size - 9999
        vector<int> dist(1e5,1e9);
        dist[src] = 0;
        
        queue<pair<int,int>>q;
        // {node, steps}
        
        q.push({src,0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(node==end)return steps;
            //if(node > end){continue;}

            for(auto it : arr){
                int product = (node*it)%100000;
                if(dist[product]>steps+1){
                    q.push({product,steps+1});
                    dist[product]=steps+1;
                }
                
            }
        }
        return -1;
    }
};