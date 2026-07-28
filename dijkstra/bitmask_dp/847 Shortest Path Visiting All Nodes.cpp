#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<>
        > pq;

        vector<vector<int>> dp(n, vector<int>((1<<n)-1, INT_MAX));
        //dp[i][max] i<- cur node, max <- all the visited nodes
        int ans = 1e5;
        for (int i = 0; i < n; i++){
            pq.push({0, i, 0});

            while (!pq.empty()){
                auto [stp, cur, mask] = pq.top(); pq.pop();

                if (stp > dp[cur][mask])
                    continue;

                mask = mask | (1<<cur);

                if (mask == (1<<n)-1)
                {
                    ans = min(ans, stp);
                    break;
                };
                

                for (int j : graph[cur]){
                    if (stp + 1 < dp[j][mask]){
                        dp[j][mask] = stp+1;
                        pq.push({stp+1, j, mask});
                    }
                }
            }
            pq = priority_queue<
                    tuple<int, int, int>,
                    vector<tuple<int, int, int>>,
                    greater<>
                >();
        }

        return ans;
    }
};
