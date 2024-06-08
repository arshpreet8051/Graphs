void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&dis,vector<int>&low,int parent,int timer,vector<vector<int>>&bridges){

    // mark as visited
    vis[node] = 1;

    // set lowest time and discovery time as current timer
    low[node] = dis[node] = timer;

    // increment timer
    timer++;

    // now traver for neighbour nodes
    for(auto neighbour : adj[node]){
        
        // if adjacent node is parent then ignore
        if(neighbour == parent)continue;

        if(vis[neighbour]==0){
            // if neighbour node is not yet visited - then call dfs on it
            dfs(neighbour,adj,vis,dis,low,node,timer,bridges);

            // after returning from above dfs call update the minimum lowest possible time
            low[node] = min(low[node],low[neighbour]);

            // now check if the edge between node----neighbour is bridge or not

            // if minimum lowest time to reach neighbour is more than the discovery time of the node 
            // then it means there is only one possiblr path from node to neighbour
            if(low[neighbour] > dis[node]){
                bridges.push_back({node,neighbour});
            }

        }

        // if neighbour is already visited and is not parent -> then "Back-Edge Case"
        else{

            // for the back edge case - simply update the lowest time of node
            low[node] = min(low[node],dis[neighbour]);

        }

    }

}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    

    // Tarjan's algorithm

/* Step - 1
            - Lets make an adjacency list
*/

    vector<int> adj[v];
    for(auto it : edges){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*
    
    Step - 2
            - Intialize different data structures
            - 1) a visited array
            - 2) array to store discovery time
            - 3) array to store lowest possible time to visite node
            - 4) parent variable
            - 5) timer variable
            - 6) 2-D matrix for storing bridges for answer
    */
    vector<vector<int>> bridges;
    vector<int>vis(v,0);
    vector<int>dis(v);
    vector<int>low(v);
    int parent = -1;
    int timer = 1;

/*  Step - 3 
                - Apply dfs to all nodes
*/
    for(int i = 0;i<v;i++){
        dfs(i,adj,vis,dis,low,parent,timer,bridges);
    }

    return bridges;

}