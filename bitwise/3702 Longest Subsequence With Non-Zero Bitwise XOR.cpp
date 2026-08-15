// You are given an integer array nums.

// Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();

        int xorr = 0;

        bool flag = false; //flag to check if non zero present

        for (int i : nums){
            if (!flag) flag = (bool) i;
            xorr ^= i;
        }

        if (!flag) return 0;

        return xorr ? n : n-1; //if xor is non zero return n else n-1 will be the answer
    }
};
