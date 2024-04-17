#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;


/*
    Note:
          - Below is the template for Disjoint set
          - Assuming 1-based indexing
*/
class Disjoint_Set{

    // data members
    private:
    vector<int>parent,rank;

    public:
    Disjoint_Set(int n){

        rank.resize(n+1,0);
        parent.resize(n+1,0);

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

    void union_by_rank(int u,int v){
        
        int ulp_u = find_ultimate_parent(u);       // ultimate parent of 'u'
        int ulp_v = find_ultimate_parent(v);       // ultimate parent of 'v'

        // already belong to same component in graph
        if(ulp_u == ulp_v){return;}

        // if belong same component - join based on ranking
        // connect smaller rank wala component to larger component wala

        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v; 
        }

        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }

        // if ranks are same
        else{
            // kuch v krde
            parent[ulp_u] = ulp_v;
            // rank v increase krega
            rank[ulp_u]++;
        }

        return;
    }
};
int main()
{

    Disjoint_Set ds(7);
    ds.union_by_rank(1,2);
    ds.union_by_rank(2,3);
    ds.union_by_rank(4,5);
    ds.union_by_rank(6,7);
    ds.union_by_rank(5,6);
    if(ds.find_ultimate_parent(3)==ds.find_ultimate_parent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    ds.union_by_rank(3,7);
    if(ds.find_ultimate_parent(3)==ds.find_ultimate_parent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }

    return 0;
}