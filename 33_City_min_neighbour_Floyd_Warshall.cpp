#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        // 2-D array to store min distances using Floyd Warshall
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        for(int i = 0;i<n;i++){
           dist[i][i] = 0;
        }
        
        // Adjacent list
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        
        int city = -1;
        int mini = INT_MAX;
        int count = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                city = i;
                mini = count;
            }
            count = 0;
        }
        
        return city;
    }
};