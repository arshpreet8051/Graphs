#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
  private:
  
    void dfs(int i,int j,vector<vector<int>>&visited,vector<vector<int>>&grid,int row,int col,int deltai[],int deltaj[]){
        
        visited[i][j] = 1;
        
        for(int x = 0;x<4;x++){
            
            int newi = i + deltai[x];
            int newj = j + deltaj[x];
            
            if(newi>=0 and newj >=0 and newi<row and newj <col and visited[newi][newj]==0 and grid[newi][newj]==1){
                dfs(newi,newj,visited,grid,row,col,deltai,deltaj);                
            }
        }
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        // make visited array
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>visited(row,vector<int>(col,0));
        
        
        int deltai[] = {0,0,-1,1};
        int deltaj[] = {-1,1,0,0};
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                
                if(i==0 || j==0 || i==row-1 || j==col-1){
                    
                    if(grid[i][j]==1){
                        
                        visited[i][j] = 1;
                        dfs(i,j,visited,grid,row,col,deltai,deltaj);
                    }
                    
                }
                
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                
                if(grid[i][j]==1 and visited[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};