#include<iostream>
#include<unordered_map>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

/*
    Space Complexity:
                        Undirected Graph -> O(2E)
                        Directed graph   -> O(E)
*/

int main()
{

    int n,m;
    cout<<"Enter no of vertices and edges :"<<endl;
    cin>>n>>m;
    unordered_map<int,vector<int>>adj_list;
    cout<<"Enter Connections between Nodes :"<<endl;
    int u,v;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i = 0;i<=n;i++){
        cout<<i<<" -> { ";
        for(int j = 0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
    return 0;
}