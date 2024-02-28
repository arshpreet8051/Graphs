#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &&

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here

    unordered_map<int,vector<int>>adj;

    for(auto x : edges){

        adj[x[0]].push_back(x[1]);

    }

    vector<int> indeg(n,0);

    for(int i = 0;i<n;i++){

        for(auto x : adj[i]){
            indeg[x]++;
        }
    }

    queue<int>q;

    for(int i = 0;i<n;i++){

        if(indeg[i]==0){
            q.push(i);
        }
    }


    vector<int> ans;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto x : adj[node]){
            indeg[x]--;

            if(indeg[x]==0){
                q.push(x);
            }
        }

    }

    return ans;


}