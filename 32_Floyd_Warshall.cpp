#include <iostream>
#include <vector>
// #include<bits/stdc++.h>
using namespace std;
#define or |
#define and &

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here

        for (auto &it1 : matrix)
        {
            for (auto &it2 : it1)
            {
                if (it2 == -1)
                {
                    it2 = 1e9;
                }
            }
        }

        int row, col;
        row = col = matrix.size();

        for (int k = 0; k < row; k++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (i != j)
                    {

                        matrix[i][j] = min((matrix[i][k] + matrix[k][j]), matrix[i][j]);
                    }
                }
            }
        }

        for (auto &it1 : matrix)
        {
            for (auto &it2 : it1)
            {
                if (it2 == 1e9)
                {
                    it2 = -1;
                }
            }
        }
        return;
    }
};