#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

#include<queue>
#include<unordered_map>
#include<vector>

string bfs_detect_cycle(int src,unordered_map<int,vector<int>>&adj_list,vector<int>&visited){

    /* Apply BFS to detect Cycle
                    - If a adjacent node is already visited 
                      before traversal and is not a parent node 
                      then cycle detected
    */

    queue<pair<int,int>>q;

    /*
        structure of queue
                            - < {current node, parent node} >
    */
        string ans = "No";

        visited[1] = 1;

        q.push(make_pair(src,-1));

        while(!q.empty()){

            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            visited[current] = 1;

            for(auto x : adj_list[current]){

                if(visited[x]==1 and x!=parent){
                    return "Yes";
                    break;
                }

                else if(visited[x]==0){
                    q.push(make_pair(x,current));
                }
            }


        }

        return ans;


}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    if(m==0)return "No";
    // make adjacency list
    unordered_map<int,vector<int>>adj_list;

    for(auto x : edges){
        int u = x[0];
        int v = x[1];

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int>visited(n+1,0);
    // keep track of visited nodes


    // applying bfs on each component - incase graph is disconnected
    for(int i = 1;i<=n;i++){

        if(visited[i]==0){
            if(bfs_detect_cycle(i,adj_list,visited)=="Yes")return "Yes";
        }
    }

    return "No";
}
