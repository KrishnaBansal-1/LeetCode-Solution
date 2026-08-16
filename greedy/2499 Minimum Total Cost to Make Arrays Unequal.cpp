// You are given two 0-indexed integer arrays nums1 and nums2, of equal length n.

// In one operation, you can swap the values of any two indices of nums1. The cost of this operation is the sum of the indices.

// Find the minimum total cost of performing the given operation any number of times such that nums1[i] != nums2[i] for all 0 <= i <= n - 1 after performing all the operations.

// Return the minimum total cost such that nums1 and nums2 satisfy the above condition. In case it is not possible, return -1.

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        
        vector<int> counts(100005, 0);
        int dominantCnt = 0;
        int dominantNum = -1;
        int involvedCnt = 0;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] == nums2[i]) {
                ans += i;
                counts[nums1[i]]++;
                if (counts[nums1[i]] > dominantCnt) {
                    dominantCnt = counts[nums1[i]];
                    dominantNum = nums1[i];
                }
                involvedCnt++;
            }
        }
        if (dominantCnt > involvedCnt / 2) {
            for (int i = 0; i < n; ++i) {
                if (nums1[i] != nums2[i] && nums1[i] != dominantNum && nums2[i] != dominantNum) {
                    counts[nums1[i]]++;
                    involvedCnt++;
                    ans += i;
                    if (dominantCnt <= involvedCnt / 2) {
                        return ans;
                    }
                }
            }
            return -1;
        }
        else {
            return ans;
        }
    }
};
