#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

  //Kahn's Algorithm :: 
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> indeg(V);
       for(int i=0;i<V;i++)
       for(int j=0;j<adj[i].size();j++)
       indeg[adj[i][j]]++;
        
        queue<int> q;
        for(int i=0;i<V;i++)
         if(indeg[i]==0)
         q.push(i);
         
       int count=0;
       
       while(!q.empty()){
           int node=q.front();
           q.pop();
           count++;
           for(auto it : adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                q.push(it);
            }
       }
       return (count!=V);
       
    }