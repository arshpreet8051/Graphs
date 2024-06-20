class Solution {
private:
    bool isValid(int i,int j,int n,int m){

        return i >=0 && j>=0 && i<n && j<m;
    }
public:
    void solve(vector<vector<char>>& board){

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){

            // for 1st col
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0] = 1;
                }

            // for last col
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1] = 1;
                }
        }

        for(int j = 0;j<m;j++){

            // for first row
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j] = 1;
                }

            // for last row
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                vis[n-1][j] = 1;
                }
        }

        int delta_x[4] = {-1,1,0,0};
        int delta_y[4] = {0,0,-1,1};

        // ignore cells that are in connection with edges
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0;i<4;i++){

                int new_x = x + delta_x[i];
                int new_y = y + delta_y[i];

                if(isValid(new_x,new_y,n,m) && board[new_x][new_y]=='O' && vis[new_x][new_y]==0){
                    vis[new_x][new_y] = 1;
                    q.push({new_x,new_y});
                }
            }
        }

        // now convert 'O' to 'X' that are not connected to edges

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){

                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }

            }
        }

    }
};