// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

class Solution {
public:
    int findit(int i, int j, vector<int> &pref, vector<vector<int>> &dp){
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        
        int front = findit(i+1, j, pref, dp);
        int back = findit(i, j-1, pref, dp);

        int total = accumulate(pref.begin()+i, pref.begin()+j+1, 0);

        return dp[i][j] = total - min(front, back);
    }
    bool predictTheWinner(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int alice = findit(0, n-1, piles, dp);
        int total = accumulate(piles.begin(), piles.end(), 0);        
 
        int bob = total - alice;

        // cout<<total<<" "<<alice<<endl;

        return alice >= bob;
    }
};
