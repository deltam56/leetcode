/**
* 3432. Count Partitions with Even Sum Difference
* You are given an integer array nums of length n.
* 
* A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
* 
* Left subarray contains indices [0, i].
* Right subarray contains indices [i + 1, n - 1].
* Return the number of partitions where the difference between the sum of the left and right subarrays is even.
* 
*  
* 
* Example 1:
* 
* Input: nums = [10,10,3,7,6]
* 
* Output: 4
* 
* Explanation:
* 
* The 4 partitions are:
* 
* [10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
* [10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
* [10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
* [10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
* Example 2:
* 
* Input: nums = [1,2,2]
* 
* Output: 0
* 
* Explanation:
* 
* No partition results in an even sum difference.
* 
* Example 3:
* 
* Input: nums = [2,4,6,8]
* 
* Output: 3
* 
* Explanation:
* 
* All partitions result in an even sum difference.
* 
*  
* 
* Constraints:
* 
* 2 <= n == nums.length <= 100
* 1 <= nums[i] <= 100**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
		vector<int> psum(nums.size());
		partial_sum(begin(nums),end(nums),begin(psum));
		int cnt = 0;
		int totsum = psum.back();
		for(int i = 0; i < psum.size()-1; ++i){
			if((2*psum[i]-totsum)%2 ==0) cnt++;
		}

		return cnt;

    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans, res;

	nums = {10,10,3,7,6};
	ans = 4;
	res = sol.countPartitions(nums);
	println("ans : {}, res : {}",ans, res);

	nums = {1,2,2};
	ans = 0;
	res = sol.countPartitions(nums);
	println("ans : {}, res : {}",ans, res);

	nums = {2,4,6,8};
	ans = 3;
	res = sol.countPartitions(nums);
	println("ans : {}, res : {}",ans, res);

    return 0;
}
