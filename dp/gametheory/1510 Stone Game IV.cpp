
// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

// Also, if a player cannot make a move, he/she loses the game.

// Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.


class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        //if current is zero player looses
        dp[0] = false;
        //if current n is one player wins after removing 1
        dp[1] = true;

        for (int i = 2; i <= n; i++){
            long long sqr = 1;
            //checking for each squares 1, 4, 9, 16, ...
            //if removing them makes other player loose
            //if yes then first player wins
            while (i - pow(sqr, 2) >= 0){
                if (dp[i - pow(sqr, 2)] == false){
                    dp[i] = true;
                    break;
                }
                sqr++;
            }
        }
        //return the nth state
        return dp[n];
    }
};
