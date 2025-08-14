/**
* 2962. Count Subarrays Where Max Element Appears at Least K Times
* You are given an integer array nums and a positive integer k.
* 
* Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
* 
* A subarray is a contiguous sequence of elements within an array.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,3,2,3,3], k = 2
* Output: 6
* Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
* Example 2:
* 
* Input: nums = [1,4,2,1], k = 3
* Output: 0
* Explanation: No subarray contains the element 4 at least 3 times.
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^6
* 1 <= k <= 10^5
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std; //편의성위해..

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int max_num = *max_element(begin(nums), end(nums));
        int l = 0, r = 0;
        unordered_map<int, int> numcount_hash;
        long long res = 0;

        for (; r < nums.size(); r++) {
            numcount_hash[nums[r]]++;
            while (numcount_hash[max_num] >= k) {
                res += nums.size() - r;
                numcount_hash[nums[l]]--;
                l++;
            }
        }
        return res;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int k;
	long long ans, res;

	nums = {1,3,2,3,3};
	k = 2;
	ans = 6;
	res = sol.countSubarrays(nums,k);
	println("ans : {} , res : {}", ans,res);

	nums = {1,4,2,1};
	k = 3;
	ans = 0;
	res = sol.countSubarrays(nums,k);
	println("ans : {} , res : {}", ans,res);

    return 0;
}
