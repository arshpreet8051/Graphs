#include <iostream>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

#include <queue>

void bfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid)
{

    vis[x][y] = 1;

    queue<pair<int, int>> q;

    q.push({x, y});

    while (!q.empty())
    {

        pair<int, int> val = q.front();

        q.pop();

        int i = val.first;

        int j = val.second;

        for (int row = -1; row <= 1; row++)
        {

            for (int col = -1; col <= 1; col++)
            {

                int nrow = i + row;

                int ncol = j + col;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&

                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
                {

                    vis[nrow][ncol] = 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int numberOfIslands(vector<vector<int>> &grid, int n, int m)

{

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 1 && vis[i][j] == 0)
            {

                cnt++;

                bfs(i, j, n, m, vis, grid);
            }
        }
    }

    return cnt;
}
