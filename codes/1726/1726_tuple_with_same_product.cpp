/**
*
* 1726. Tuple with Same Product
* Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.
*
*/
#include <cassert>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int tupleSameProduct(vector<int>& nums) {
		const int n = nums.size();
		int cnt = 0;
		unordered_map<int, int> hmap;

		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j) {
				int prod = nums[i] * nums[j];
				cnt += hmap[prod] * 8;
				hmap[prod]++;
			}

		return cnt;
	}
};

int main()
{
	Solution sol;
	vector<int> nums;
	int ret;

	nums = {2,3,4,6};
	ret = sol.tupleSameProduct(nums);
	assert(ret == 8);
	cout << ret << endl;

	nums = {1,2,4,5,10};
	ret = sol.tupleSameProduct(nums);
	assert(ret == 16);
	cout << ret << endl;

	return 0;
}
