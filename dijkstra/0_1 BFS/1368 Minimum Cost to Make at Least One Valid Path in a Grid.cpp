#include <bits/stdc++.h>
using namespace std;

// Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

// 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
// 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
// 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
// 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
// Notice that there could be some signs on the cells of the grid that point outside the grid.

// You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

// You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

// Return the minimum cost to make the grid have at least one valid path.

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>, 
            greater<>
        > pq;

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        pq.push({0, 0, 0});

        int dx[5] = {1, 0, -1, 0, 1};
        int dir[4] = {3, 2, 4, 1};

        while (!pq.empty()){
            auto [stp, i, j] = pq.top(); pq.pop();

            if (stp > dp[i][j])
                continue;
            
            if (i == n-1 && j == m-1)
                return stp;

            for (int x = 0; x < 4; x++){
                int ii = i + dx[x];
                int jj = j + dx[x+1];
                
                if (ii < 0 || jj < 0 || ii >= n || jj >= m)
                    continue;
                
                int cost = (dir[x] == grid[i][j]) ? 0 : 1;
                
                if (dp[ii][jj] > stp + cost){
                    dp[ii][jj] = stp + cost;
                    pq.push({dp[ii][jj], ii, jj});
                }
            }
        }
        return -1;
    }
};
