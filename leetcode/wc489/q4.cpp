/*
You are given a non-negative integer array nums and an integer k.

You must select a subarray of nums such that the difference between its maximum and minimum elements is at most k. The value of this subarray is the bitwise XOR of all elements in the subarray.

Return an integer denoting the maximum possible value of the selected subarray.

A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();

        // Check every possible subarray
        // Complexity: O(N^2) - Correctness guaranteed, but may be slow for large N.
        for (int i = 0; i < n; ++i) {
            int current_min = nums[i];
            int current_max = nums[i];
            int current_xor = 0;
            
            for (int j = i; j < n; ++j) {
                current_min = min(current_min, nums[j]);
                current_max = max(current_max, nums[j]);
                current_xor ^= nums[j];
                
                if (current_max - current_min <= k) {
                    ans = max(ans, current_xor);
                } else {
                     // Optimization: If the difference exceeds k, adding more elements
                     // will only maintain or increase the difference (max increases or min decreases).
                     // So we can stop extending this subarray.
                    break;
                }
            }
        }

        return ans;
    }
};