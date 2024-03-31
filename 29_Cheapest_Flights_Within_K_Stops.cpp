#include<bits/stdc++.h>
int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    // Here direct Dijkstra will not work
    // We will not even use priorty queue coz we need to focus on stops and increase with unit weight at each step
    
    // adj list
    vector<pair<int,int>> adj[n];
    //[from-node]->{to-node, ticket}

    for(auto it : trains){
        int from_node = it[0];
        int to_node = it[1];
        int ticket = it[2];

        adj[from_node].push_back({to_node,ticket});
    }

    queue<pair<pair<int,int>,int>>q;
    // {{node,ticket},stops}

    // dist array
    vector<int>dist(n,1e9);
    dist[source] = 0;

    q.push({{source,0},0});

    while(!q.empty()){

        auto it = q.front();
        q.pop();

        int node = it.first.first;
        int ticket = it.first.second;
        int stops = it.second;

        if(stops>K){continue;}

        for(auto iter : adj[node]){

            int adjNode = iter.first;
            int adjW = iter.second;

            if(ticket + adjW < dist[adjNode] and stops<=K){
                dist[adjNode] = ticket + adjW;
                q.push({{adjNode,dist[adjNode]},stops+1});
            }

        }
    }

    if(dist[destination]==1e9)return -1;
    return dist[destination];
}