// link -> https://leetcode.com/problems/01-matrix/description/

// Distance to nearest zero's

class Solution {
private:
    bool isValid(int i,int j,int n,int m){

        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q; // {{i,j},dis}

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){

                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        int delta_x[4] = {-1,1,0,0};
        int delta_y[4] = {0,0,-1,1};

        while(!q.empty()){

            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;

            q.pop();

            for(int i = 0;i<4;i++){

                int new_x = x + delta_x[i];
                int new_y = y + delta_y[i];

                if(isValid(new_x,new_y,n,m) && vis[new_x][new_y]==0){

                    vis[new_x][new_y] = 1;
                    ans[new_x][new_y] = dis+1;
                    q.push({{new_x,new_y},dis+1});
                }
            }
        }

        return ans;


    }
};