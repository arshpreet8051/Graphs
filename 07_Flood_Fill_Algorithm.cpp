#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
#define or |
#define and &
 
class Solution {
    
private:
    void dfs(vector<vector<int>>&image,int x,int y,int row,int col,int initialColor,int newColor,int* deltarow,int* deltacol){
        
        if(x<0 or x>=row or y<0 or y>=col or image[x][y]!=initialColor){return;}
        
        image[x][y] = newColor;
        
        for(int i = 0;i<4;i++){
            
            int newRow = x + deltarow[i];
            int newCol = y + deltacol[i];
            
            if(newRow>=0 and newRow<row and newCol>=0 and newCol < col){
                dfs(image,newRow,newCol,row,col,initialColor,newColor,deltarow,deltacol);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int row = image.size();
        int col = image[0].size();
        
        int initialColor = image[sr][sc];
        
        int deltarow[] = {-1,0,1,0};
        int deltacol[] = {0,1,0,-1};
        
        dfs(image,sr,sc,row,col,initialColor,newColor,deltarow,deltacol);
        
        return image;
        
        
    }
};