// You are given an integer array nums and an integer k.

// The frequency of an element x is the number of times it occurs in an array.

// An array is called good if the frequency of each element in this array is less than or equal to k.

// Return the length of the longest good subarray of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++){
            mp[nums[j]]++;

            while (mp[nums[j]] > k)
                mp[nums[i++]]--;
            
            ans = max(ans, j-i+1);
        }

        return ans;
    }
};
