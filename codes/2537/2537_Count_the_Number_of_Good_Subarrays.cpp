/**
 * 2537. Count the Number of Good Subarrays
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * 
 * A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,1,1,1], k = 10
 * Output: 1
 * Explanation: The only good subarray is the array nums itself.
 * Example 2:
 * 
 * Input: nums = [3,1,4,3,2,2,4], k = 2
 * Output: 4
 * Explanation: There are 4 different good subarrays:
 * - [3,1,4,3,2,2] that has 2 pairs.
 * - [3,1,4,3,2,2,4] that has 3 pairs.
 * - [1,4,3,2,2,4] that has 2 pairs.
 * - [4,3,2,2,4] that has 2 pairs.
 * 
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long result = 0;
        int n = nums.size();
        int l = 0;
        long long pairs = 0;

        for (int r = 0; r < n; r++) {
            pairs += freq[nums[r]];
            freq[nums[r]]++;

            while (pairs >= k) {
                result += (n - r);
                pairs -= freq[nums[l]] - 1;
                freq[nums[l]]--;
                l++;
            }
        }
        return result;
    }
};

int main() {
	Solution sol;
	long long ans = 0 ,res = 0;
	vector<int> nums;
	int k;

	nums = {1,1,1,1,1};
	k = 10;
	ans = 1;
	res = sol.countGood(nums,k);
	println("ans : {} , res : {}", ans , res);

	nums = {3,1,4,3,2,2,4};
	k = 2;
	ans = 4;
	res = sol.countGood(nums,k);
	println("ans : {} , res : {}",ans , res);

	return 0;
}
