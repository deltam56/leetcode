/**
*
* 1749. Maximum Absolute Sum of Any Subarray
* You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
* 
* Return the maximum absolute sum of any (possibly empty) subarray of nums.
* 
* Note that abs(x) is defined as follows:
* 
* - If x is a negative integer, then abs(x) = -x.
* - If x is a non-negative integer, then abs(x) = x.
*  
* 
* Example 1:
* 
* Input: nums = [1,-3,2,3,-4]
* Output: 5
* Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
* Example 2:
* 
* Input: nums = [2,-5,1,-4,3,-2]
* Output: 8
* Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* -10^4 <= nums[i] <= 10^4
**/

#include <iostream>
#include <numeric>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std; //편의성위해..

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
		partial_sum(begin(nums), end(nums), begin(nums));

		int max = *max_element(begin(nums),end(nums));
		int min = *min_element(begin(nums),end(nums));
		
		if(signbit(max) == signbit(min))
		   return abs(max)>abs(min) ? abs(max):abs(min);


		return max - min;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,-3,2,3,-4};
	ans = 5;
	res = sol.maxAbsoluteSum(nums);
	println("ans : {} res :{}",ans,res);
	assert(ans==res);

	nums = {2,-5,1,-4,3,-2};
	ans = 8;
	res = sol.maxAbsoluteSum(nums);
	println("ans : {} res : {}",ans,res);
	assert(ans==res);

	nums = {-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8};
	ans = 27;
	res = sol.maxAbsoluteSum(nums);
	println("ans : {} res : {}",ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
    return 0;
}

