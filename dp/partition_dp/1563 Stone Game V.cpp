// There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// In each round of the game, Alice divides the row into two non-empty rows (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

// The game ends when there is only one stone remaining. Alice's score is initially zero.

// Return the maximum score that Alice can obtain.

class Solution {
public:
    int findit(int i, int j, int n, int total, vector<int> &sv, vector<vector<int>>& dp){
        if (i >= j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        int sum = 0;

        for (int x = i; x <= j; x++){
            sum += sv[x];
            int cur = min(sum, total-sum);
            int here = 0;
            
            if (total-sum >= sum)
                here = max(here, sum + findit(i, x, n, sum, sv, dp));
            if (sum >= total-sum)
                here = max(here, total-sum+findit(x+1, j, n, total-sum, sv, dp));
            
            ans = max(ans, here);
        }

        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneVal) {
        int n = stoneVal.size();
        int sum = accumulate(stoneVal.begin(), stoneVal.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return findit(0, n-1, n, sum, stoneVal, dp);

    }
};
