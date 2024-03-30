#include<bits/stdc++.h>
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
    // we will follow the BFS approach
    // start from src with length 0
    // for every neighbour with value one - push in queue with len + 1
    // if neighbour is dest return - len

    int n = matrix.size();
    int m = matrix[0].size();

    int final_x = dest.first;
    int final_y = dest.second;

    if(matrix[final_x][final_y]!=1)return -1;

    int src_x = src.first;
    int src_y = src.second;

    if(matrix[src_x][src_y]!=1)return -1;

    // to keep a track of distances
    // only visit the next node if it is providing some smaller lenght path
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[src_x][src_y] = 0;

    vector<int>delta_x = {-1,0,1,0};
    vector<int>delta_y = {0,-1,0,1};

    queue<vector<int>>q;

    q.push({src_x,src_y,0});

    int ans = INT_MAX;

    while(!q.empty()){

        vector<int> front = q.front();
        int x = front[0];
        int y = front[1];
        int len = front[2];

        q.pop();

        if(x==final_x and y==final_y){
            return len;
        }

        for(int i = 0;i<4;i++){
            int new_x = x + delta_x[i];
            int new_y = y + delta_y[i];

            if( (new_x<n and new_x>=0) and (new_y<m and new_y>=0) and (matrix[new_x][new_y]==1) and (len+1 < dist[new_x][new_y])){
                
                dist[new_x][new_y] = len+1;
                q.push({new_x,new_y,len+1});
            }
        }


    }

    //if(ans==INT_MAX)return -1;
    return -1;
}

//---------------------------------------------------------------------------------------------------

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        
        // we will apply Dijkstra to get the minimum path
        int n = grid.size();
        int m = grid[0].size();
        
        int src_x = source.first;
        int src_y = source.second;
        
        int final_x = destination.first;
        int final_y = destination.second;
        
        // Handling edge cases
        if((grid[src_x][src_y]!=1) or (grid[final_x][final_y]!=1)){return -1;}
        
        // making 2-D array to compare distance every time and only proceed if there is chance of shorter distance
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src_x][src_y] = 0;
        
        int delta_x[4] = {-1,1,0,0};
        int delta_y[4] = {0,0,-1,1};
        
        // Note : Not using priority queue as weight is only unit for every node so simple queue will work
        queue<vector<int>>q;
        
        q.push({src_x,src_y,0});
        
        while(!q.empty()){
            
            vector<int> front = q.front();
            int x = front[0];
            int y = front[1];
            int len = front[2];
            
            q.pop();
            
            if(x==final_x and y==final_y){return len;}
            
            for(int i = 0;i<4;i++){
                
                int new_x = x + delta_x[i];
                int new_y = y + delta_y[i];
                
                if( (new_x>=0 and new_x<n) and (new_y>=0 and new_y<m) and grid[new_x][new_y]==1 and (1 + len < dist[new_x][new_y])){
                    dist[new_x][new_y] = 1 + len;
                    q.push({new_x,new_y,len+1});
                }
            }
        }
        
        return -1;
        
    }
};