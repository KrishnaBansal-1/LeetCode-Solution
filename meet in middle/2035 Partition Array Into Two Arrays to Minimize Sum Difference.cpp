// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of
// the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;

        long long totsum = accumulate(nums.begin(), nums.end(), 0LL);
        
        


        unordered_map<int, vector<long long>> mp1, mp2;

        for (int i = 0; i < (1<<n); i++){
            long long sum = 0;
            int taken = 0;
            for (int j = 0; j < n; j++){
                if ((1 << j) & i){
                    taken++;
                    sum += (long long) nums[j];
                }
            }
            mp1[taken].push_back(sum);
        }

        for (int i = 0; i < (1<<n); i++){
            long long sum = 0;
            int taken = 0;
            for (int j = 0; j < n; j++){
                if ((1 << j) & i){
                    taken++;
                    sum += (long long) nums[n+j];
                }
            }
            mp2[taken].push_back(sum);
        }
        long long ans = 1e10;
        for (int take = 0; take < n; take++){

            vector<long long> cur = mp1[take];
            int req = n-take;
            vector<long long> targ = mp2[req];
            sort(targ.begin(), targ.end());

            for (int i = 0; i < cur.size(); i++){
                long long have = cur[i];
                long long need = (totsum - 2*have)/2;

                int idx = lower_bound(targ.begin(), targ.end(), need) - targ.begin();

                if (idx < targ.size())
                    ans = min(ans, llabs(totsum - 2LL*(targ[idx] + have)));
                if (idx > 0)
                    ans = min(ans, llabs(totsum - 2LL*(targ[idx-1] + have)));
            }
        }

        return ans;
    }


};
