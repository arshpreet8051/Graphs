#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

class Graph {
private:
    bool dfs(int src,int parent,vector<int>adj[],vector<int>&visited){

        visited[src] = 1;

        for(auto x : adj[src]){

            if(visited[x]==1 and x!=parent){
                return true;
            }
            else if(visited[x]==0){
                if(dfs(x,src,adj,visited))return true;
            }

        }

        return false;

    }

public:
    bool detectCycle(int n, vector<int> adj[]) {
        
        vector<int>visited(n,0);

        for(int i = 0;i<n;i++){

            if(visited[i]==0){

                if(dfs(i,-1,adj,visited))return true;

            }
        }

        return false;
        
    }
};
 