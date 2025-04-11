/**
* 3375. Minimum Operations to Make Array Values Equal to K
* You are given an integer array nums and an integer k.
* 
* An integer h is called valid if all values in the array that are strictly greater than h are identical.
* 
* For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.
* 
* You are allowed to perform the following operation on nums:
* 
* - Select an integer h that is valid for the current values in nums.
* - For each index i where nums[i] > h, set nums[i] to h.
* Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.
* 
* 
* 
* Example 1:
* 
* Input: nums = [5,2,5,4,5], k = 2
* 
* Output: 2
* 
* Explanation:
* 
* The operations can be performed in order using valid integers 4 and then 2.
* 
* Example 2:
* 
* Input: nums = [2,1,2], k = 2
* 
* Output: -1
* 
* Explanation:
* 
* It is impossible to make all the values equal to 2.
* 
* Example 3:
* 
* Input: nums = [9,7,5,3], k = 1
* 
* Output: 4
* 
* Explanation:
* 
* The operations can be performed using valid integers in the order 7, 5, 3, and 1.
* 
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 100
* 1 <= nums[i] <= 100
* 1 <= k <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <set>
#include <utility>


using namespace std; //편의성위해..
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
		auto cmp = [](int a, int b) { return a > b; };
		set<int, decltype(cmp)> marker_set(cmp);
		int m = nums.size();
		int count = 0;
		for(int n : nums){
			marker_set.insert(n);
		}
		marker_set.insert(k);
		for(auto it = marker_set.begin();it!= marker_set.end();++it){
			set<int> numcount;
			for(int i = 0 ; i < m ; ++i){
				if(nums[i] >= *it){
					nums[i] = *it;
				}
				numcount.insert(nums[i]);
			}
			if(numcount.size() == 1 && *numcount.begin() == k){
				return count;
			}
			count ++;
		}
		return -1;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int k = 0;
	int ans = 0 ,res = 0;

	nums = {5,2,5,4,5};
	k = 2;
	ans = 2;
	res = sol.minOperations(nums,k);
	println("ans : {} , res : {} ",ans , res);

	nums = {2,1,2};
	k = 2;
	ans = -1;
	res = sol.minOperations(nums,k);
	println("ans : {} , res : {} ",ans , res);

	nums = {9,7,5,3};
	k = 1;
	ans = 4;
	res = sol.minOperations(nums,k);
	println("ans : {} , res : {} ",ans , res);

    return 0;
}
