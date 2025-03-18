/**
* 2401. Longest Nice Subarray
* You are given an array nums consisting of positive integers.
* 
* We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
* 
* Return the length of the longest nice subarray.
* 
* A subarray is a contiguous part of an array.
* 
* Note that subarrays of length 1 are always considered nice.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,3,8,48,10]
* Output: 3
* Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
* - 3 AND 8 = 0.
* - 3 AND 48 = 0.
* - 8 AND 48 = 0.
* It can be proven that no longer nice subarray can be obtained, so we return 3.
* Example 2:
* 
* Input: nums = [3,1,5,11,13]
* Output: 1
* Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
#if 0
		int res = 0;
		int count = 1;
		int l = 0;
		int r = 1;
		
		if(nums.size() == 1)
			return 1;

		while(l < r)
		{
			if(!(nums[l] & nums[r])){
				if(r<nums.size()-1)
					r ++;
				count ++;
			}else{
				if(r-1 == l && r< nums.size()-1)
					r ++;
				l ++;
				count = count > 1? count--:1;
			}
			res = res>count? res:count;
		}
		return res;
#else
		int used = 0, l = 0, res = 0;
        for (int r = 0; r < nums.size(); r++) {
            while ((used & nums[r]) != 0) {
                used ^= nums[l];
                l++;
            }
            used |= nums[r];
            res = max(res, r - l + 1);
        }

        return res;
#endif
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans = 0;
	int res = 0;

	nums = {1,3,8,48,10};
	ans = 3;
	res = sol.longestNiceSubarray(nums);
	println("ans : {} , res : {}",ans , res);


	nums = {3,1,5,11,13};
	ans = 1;
	res = sol.longestNiceSubarray(nums);
	println("ans : {} , res : {}",ans , res);


	cout << "Accepted!" <<endl;
    return 0;
}
