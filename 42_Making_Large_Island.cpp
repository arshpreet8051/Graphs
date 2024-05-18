/*

Problem Explanation:

You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

You can change at most one cell in grid from 0 to 1.

You need to find the largest group of connected  1's.

*/

/* ---------------------------------------------------------------------------------------------*/

// Disjoint Set Solution - T.C. - O(n^2)


class disjoint_set{
  
  public:
  
  vector<int>parent,size;
  
  disjoint_set(int n){
      
      parent.resize(n+1);
      size.resize(n+1,1);
      
      for(int i=0;i<=n;i++){
          parent[i] = i;
      }
  }
  
  int find_ultimate_parent(int node){
      
      // base case
      if(parent[node]==node)return node;
      
      return parent[node] = find_ultimate_parent(parent[node]);
      
  }
  
  void union_by_size(int u,int v){
      
      int ulp_u = find_ultimate_parent(u);
      int ulp_v = find_ultimate_parent(v);
      
      if(ulp_u==ulp_v)return;
      
      if(size[ulp_u] > size[ulp_v]){
          parent[ulp_v] = ulp_u;
          size[ulp_u] += size[ulp_v];
      }
      else{
          parent[ulp_u] = ulp_v;
          size[ulp_v] += size[ulp_u];
      }
  }
    
};

class Solution {
  private:
  bool isValid(int row,int col,int n){
      
      return row>=0 and row<n and col >=0 and col<n;
      
  }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        // note -> visited array di lod nahi coz ultimate parent wali game chalni a
        
        disjoint_set ds = disjoint_set(n * n);
        
        int delta_row[4] = {0,0,-1,1};
        int delta_col[4] = {-1,1,0,0};
        
        // step -1 
        //         Traverse grid and connect components with one as a single unit using union by size and marking their ultimate parent
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n;col++){
                
                if(grid[row][col] == 0)continue;
                
                for(int ind = 0;ind<4;ind++){
                    
                    int new_row = row + delta_row[ind];
                    int new_col = col + delta_col[ind];
                    
                    if(isValid(new_row,new_col,n) && grid[new_row][new_col]==1){
                        
                        int node_number = (row * n) + col;
                        int adjNode_number = (new_row * n) + new_col;
                        
                        ds.union_by_size(node_number,adjNode_number);
                        
                    }
                    
                }
            }
        }
        
        
        // step - 2
        //          Traverse the grid - find 0 - find it's adjacent components of 1 and put in set to avoid repetition
        
        int mx = 0;
        
        for(int row = 0;row < n;row++){
            for(int col = 0;col < n;col++){
                
                if(grid[row][col]==1)continue;
                set<int> components;
                
                for(int ind = 0;ind<4;ind++){
                    
                    int new_row = row + delta_row[ind];
                    int new_col = col + delta_col[ind];
                    
                    if(isValid(new_row,new_col,n)){
                    
                        if(grid[new_row][new_col]==1){
                            
                            int node_number = (row * n) + col;
                            int adjNode_number = (new_row * n) + new_col;
                            
                            components.insert(ds.find_ultimate_parent(adjNode_number));
                            
                        }
                    }
                }
                
                int total_size = 0;
                for(auto it : components){
                    total_size += ds.size[it];
                }
                
                // add 1 for the '0' that we converted to '1'
                total_size += 1;
                mx = max(mx,total_size);
            }
        }
        
        // Edge Case
        //           The matrix might consist of all '1'
        
       for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    int node_number = (row * n) + col;
                    mx = max(mx, ds.size[ds.find_ultimate_parent(node_number)]);
                }
            }
        }
        
        return mx;
    }
};



/*

Brute Force: -- TLE



class Solution {
    
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    
    int max_connections(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        ans++;
                        
                        int deltai[4] = {1, -1, 0, 0};
                        int deltaj[4] = {0, 0, -1, 1};
                        
                        for (int k = 0; k < 4; ++k) {
                            int new_i = x + deltai[k];
                            int new_j = y + deltaj[k];
                            
                            if (isValid(new_i, new_j, n) && grid[new_i][new_j] == 1 && !visited[new_i][new_j]) {
                                q.push({new_i, new_j});
                                visited[new_i][new_j] = true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    ans = max(ans, max_connections(grid));
                    grid[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
*/