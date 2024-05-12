#include<bits/stdc++.h>
using namespace std;

class Disjoint_Set{

    // data members
    private:
    vector<int>parent,size;

    public:
    Disjoint_Set(int n){

        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i = 0;i<=n;i++){

            parent[i] = i;

        }
    }

    int find_ultimate_parent(int node){

        // base case
        if(parent[node] == node){
            return node;
        }
        
        // Recursion with Path compression
        // Parent da parent find krna -> ultimate parent
        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void union_by_size(int u,int v){
        
        int ulp_u = find_ultimate_parent(u);       // ultimate parent of 'u'
        int ulp_v = find_ultimate_parent(v);       // ultimate parent of 'v'

        // already belong to same component in graph
        if(ulp_u == ulp_v){return;}

        // if belong same component - join based on sizeing
        // connect smaller size wala component to larger size wala component 

        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u];
        }

        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        return;
    }
};

bool isValid(int row,int col, int n, int m){

    return row>=0 && row<n && col>=0 && col<m;
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	
    // we will consider each cell as single entitiy
    Disjoint_Set ds = Disjoint_Set(n*m);
    
    // visited array to keep track of already made computations
    int visited[n][m];
    memset(visited,0,sizeof visited);

    int drow[4] = {-1,0,1,0};
    int dcol[4]  = {0,1,0,-1};
    
    int cnt = 0;
    vector<int> ans;

    for(auto it : q){

        int row = it[0];
        int col = it[1];

        if(visited[row][col]==1){
            ans.push_back(cnt);
            continue;
        }

        visited[row][col] = 1;
        cnt++;

        for(int i = 0;i<4;i++){

            int adjr = row + drow[i];
            int adjc = col + dcol[i];

            if(isValid(adjr,adjc,n,m)){
                
                if(visited[adjr][adjc]){

                    // formula to locate node using row and col
                    // node position = row * no' of columns + current column position

                    int node = row * m + col;
                    int adjNode = adjr * m + adjc;

                    if (ds.find_ultimate_parent(node) != ds.find_ultimate_parent(adjNode)) {
                    
                      cnt--;
                      ds.union_by_size(node, adjNode);
                    
                    }
                }

            }
        }
        ans.push_back(cnt);
    }
    
    return ans;
}