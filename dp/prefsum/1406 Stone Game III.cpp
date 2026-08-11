// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

// The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

// Assume Alice and Bob play optimally.

// Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

class Solution {
public:
    int findscore(int i, int n, vector<int> &sufsum, vector<int> &dp){
        if (i >= n)
            return 0;
        
        int ans = 1e9;

        if (dp[i] != -1)
            return dp[i];

        for (int j = 1; j <= 3; j++){
            ans = min(ans, findscore(i+j, n, sufsum, dp));
        }

        return dp[i] = sufsum[i] - ans;
    }
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int> sufsum(n, 0);

        sufsum[n-1] = sv[n-1];

        vector<int> dp(n, -1);

        for (int i = n-2; i >= 0; i--){
            sufsum[i] = sufsum[i+1] + sv[i];
        }        

        int getalice = findscore(0, n, sufsum, dp);
        int getbob = sufsum[0] - getalice;

        if (getalice > getbob)
            return "Alice";
        
        if (getbob > getalice)
            return "Bob";
        
        return "Tie";
    }   
};
