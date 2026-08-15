// You are given an integer array nums and an integer goal.

// You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).

// Return the minimum possible value of abs(sum - goal).

// Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<long long> subsum1;
        vector<long long> subsum2;

        int n1 = n / 2;
        int n2 = n - n1;

        for (int i = 0; i < (1 << n1); i++) {
            long long sum = 0;

            for (int j = 0; j < n1; j++) {
                if ((1 << j) & i)
                    sum += (long long)nums[j];
            }

            subsum1.push_back(sum);
        }

        for (int i = 0; i < (1 << n2); i++) {
            long long sum = 0;

            for (int j = 0; j < n2; j++) {
                if ((1 << j) & i)
                    sum += (long long)nums[n1 + j];
            }

            subsum2.push_back(sum);
        }

        sort(subsum2.begin(), subsum2.end());

        long long ans = LLONG_MAX;

        for (int i = 0; i < (1 << n1); i++) {
            long long cur = subsum1[i];
            long long req = (long long)goal - cur;

            int idx = lower_bound(subsum2.begin(), subsum2.end(), req) - subsum2.begin();

            if (idx < (int)subsum2.size()) {
                ans = min(ans, llabs(req - subsum2[idx]));
            }

            if (idx > 0) {
                ans = min(ans, llabs(req - subsum2[idx - 1]));
            }
        }

        return (int)ans;
    }
};
