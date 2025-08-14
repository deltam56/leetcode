/**
* 2040. Kth Smallest Product of Two Sorted Arrays
* Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
* 
* 
* Example 1:
* 
* Input: nums1 = [2,5], nums2 = [3,4], k = 2
* Output: 8
* Explanation: The 2 smallest products are:
* - nums1[0] * nums2[0] = 2 * 3 = 6
* - nums1[0] * nums2[1] = 2 * 4 = 8
* The 2nd smallest product is 8.
* Example 2:
* 
* Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
* Output: 0
* Explanation: The 6 smallest products are:
* - nums1[0] * nums2[1] = (-4) * 4 = -16
* - nums1[0] * nums2[0] = (-4) * 2 = -8
* - nums1[1] * nums2[1] = (-2) * 4 = -8
* - nums1[1] * nums2[0] = (-2) * 2 = -4
* - nums1[2] * nums2[0] = 0 * 2 = 0
* - nums1[2] * nums2[1] = 0 * 4 = 0
* The 6th smallest product is 0.
* Example 3:
* 
* Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
* Output: -6
* Explanation: The 3 smallest products are:
* - nums1[0] * nums2[4] = (-2) * 5 = -10
* - nums1[0] * nums2[3] = (-2) * 4 = -8
* - nums1[4] * nums2[0] = 2 * (-3) = -6
* The 3rd smallest product is -6.
* 
* 
* Constraints:
* 
* 1 <= nums1.length, nums2.length <= 5 * 10^4
* -105 <= nums1[i], nums2[j] <= 10^5
* 1 <= k <= nums1.length * nums2.length
* nums1 and nums2 are sorted.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int size1 = nums1.size();
		int size2 = nums2.size();
		int count = 0;

		for(int i = 0 ; i < size1 ; ++i){
			if(nums1[i] >= 0 ){
				for(int j = 0 ; j < size2 ; ++j){
					count++;
					if(count == k){
						return nums1[i] * nums2[j];
					}
				}
			} else {
				for(int j = size2-1; j > 0 ; --j){
					count++;
					if(count == k){
						return nums1[i] * nums2[j];
					}
				}
			}
		}
		return 0;
    }
};
#else
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int size1 = nums1.size();
		int size2 = nums2.size();
		int count = 0;

		// 하나를 절대값으로 정렬
		// 

		return 0;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums1,nums2;
	long long k;
	long long ans,res;

	nums1 = {2,5}, nums2 = {3,4};
	k = 2;
	ans = 8;
	res = sol.kthSmallestProduct(nums1,nums2,k);
	println("ans : {} , res : {}",ans,res);

	nums1 = {-4,-2,0,3}, nums2 = {2,4};
	k = 6;
	ans = 0;
	res = sol.kthSmallestProduct(nums1,nums2,k);
	println("ans : {} , res : {}",ans,res);

	nums1 = {-2,-1,0,1,2}, nums2 = {-3,-1,2,4,5};
	k = 3;
	ans = -6;
	res = sol.kthSmallestProduct(nums1,nums2,k);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
