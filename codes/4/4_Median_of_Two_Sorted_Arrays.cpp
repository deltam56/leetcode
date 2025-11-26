/**
 * 4. Median of Two Sorted Arrays
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Constraints:
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -106 <= nums1[i], nums2[i] <= 106
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> mergednums = nums1;
		mergednums.insert(end(mergednums), begin(nums2), end(nums2));

		sort(mergednums.begin(), mergednums.end());

		int s = mergednums.size();

		if (s % 2 == 0)
			return (mergednums[s/2 - 1] + mergednums[s/2]) / 2.0;
		return static_cast<double>(mergednums[s/2]);;
	}
};

int main() {
	Solution sol;
	vector<int> nums1,nums2;
	double ans,res;

	nums1 = {1,3}, nums2 = {2};
	ans = 2.00000;
	res = sol.findMedianSortedArrays(nums1,nums2);
	println("ans : {}, res : {}",ans,res);

	nums1 = {1,2}, nums2 = {3,4};
	ans = 2.50000;
	res = sol.findMedianSortedArrays(nums1,nums2);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
