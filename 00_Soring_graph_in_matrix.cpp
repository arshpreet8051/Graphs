#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
// #define or |
// #define and &

// Adjacent Matrix 

int main()
{
    int n,m;
    cout<<"Enter No of vertices and edges"<<endl;
    cin>>n>>m;
    vector<vector<int>>mat(n+1,vector<int>(m+1,0));
    cout<<"Enter connection between vertices"<<endl;
    int u,v;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        mat[u][v] = mat[v][u] = 1;
    }

    for(int i = 0;i<=n;i++){
        for(int j = 0 ;j<=m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}