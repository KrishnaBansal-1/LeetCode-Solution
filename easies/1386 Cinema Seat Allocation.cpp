// A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.

// You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.

// A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

// seats 2, 3, 4, 5
// seats 4, 5, 6, 7
// seats 6, 7, 8, 9
// A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.

// Return an integer denoting the maximum number of four-person groups that can be assigned.

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int ans = 0;
        int sz = rs.size();
        int maxirow = 0;

        sort(rs.begin(), rs.end());

        for (int i = 0; i < sz; i++){

            bool lft = 1, mid = 1, rht = 1;
            int cur = rs[i][0];
            maxirow++;

            while (i < sz && rs[i][0] == cur){
                int now = rs[i][1];
                if (now >= 2 && now <= 5)
                    lft = false;
                if (now >= 6 && now <= 9)
                    rht = false;
                if (now >= 4 && now <= 7)
                    mid = false;
                i++;
            }
            i--;
            if (lft && rht)
                ans += 2;
            else if (mid || lft || rht)
                ans += 1;
        }

        int left = n - maxirow;
        ans += left * 2;

        return ans;
    }
};
