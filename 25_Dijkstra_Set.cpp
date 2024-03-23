#include<bits/stdc++.h>

class solution{
vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int edge, int source) {
    // Write your code here.
    vector<int> dist(vertices,INT_MAX);

    vector<vector<int>>adj[vertices];

    for(auto it : edges){

        int u = it[0];
        int v = it[1];
        int w = it[2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    set<pair<int,int>>st;

    dist[source] = 0;

    st.insert({0,source});

    while(!st.empty()){

        auto it = *(st.begin());

        int w = it.first;
        int node = it.second;

        st.erase(it);
        
        for(auto vec : adj[node] ){

            int adjNode = vec[0];
            int adjDist = vec[1];

            if( w + adjDist < dist[adjNode]){

                dist[adjNode] = w + adjDist;

                st.insert({dist[adjNode],adjNode});
            }
        }
    }

    return dist;
}
};