#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

// 0 represents an empty cell,
// 1 represents an obstacle that may be removed.
// You can move up, down, left, or right from and to an empty cell.

// Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

class Solution {
public:

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i = 0, j = 0;

        vector<int> dx = {1, 0, -1, 0, 1};

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;

        pq.push({grid[i][j], i, j});

        vector<vector<int>> dp(n, vector<int>(m, 1e9));

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

                if (dp[ii][jj] > stp + grid[ii][jj]){
                    dp[ii][jj] = stp + grid[ii][jj];
                    pq.push({dp[ii][jj], ii, jj});
                }
            }
        } 
        return -1;
    }
};
