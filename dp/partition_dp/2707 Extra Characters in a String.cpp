// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.

class Solution {
public:
    int findit(int idx, string s, int n, unordered_set<string> &dict, vector<int> &dp){
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx] != -1) 
            return dp[idx];

        int take = 1e9;
        for (int i = idx; i < n; i++){
            string sub = s.substr(idx, i - idx + 1);
            if (dict.find(sub) != dict.end())
                take = min(take, findit(i+1, s, n, dict, dp));
        }
        take = min(take, 1 + findit(idx+1, s, n, dict, dp));

        return dp[idx] = take;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        unordered_set<string> sett(dict.begin(), dict.end());

        return findit(0, s, n, sett, dp);
    }
};
