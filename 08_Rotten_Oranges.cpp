#include<iostream>
#include<queue>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        int deltaRow[] = {1,-1,0,0};
        int deltaCol[] = {0,0,-1,1};
        
        queue<pair<pair<int,int>,int>>q;
        // structure of queue
        
        // q -> { {row,col} ,time}
        // time -> means the time when oranges were rotten
        
        
        // traverse the grid and push in queue the already rotten once
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                
            }
        }
        
        
        int ans = 0;
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            ans = max(ans,t);
            
            for(int x = 0;x<4;x++){
                
                int newRow = r + deltaRow[x];
                int newCol = c + deltaCol[x];
                
                
                if(newRow>=0 and newRow<row and newCol>=0 and newCol<col and grid[newRow][newCol]==1){
                    q.push({{newRow,newCol},t+1});
                    grid[newRow][newCol] = 2;
                }
            }
        }
        
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};