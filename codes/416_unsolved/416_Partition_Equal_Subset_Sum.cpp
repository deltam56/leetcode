/**
* 416. Partition Equal Subset Sum
* Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,5,11,5]
* Output: true
* Explanation: The array can be partitioned as [1, 5, 5] and [11].
* Example 2:
* 
* Input: nums = [1,2,3,5]
* Output: false
* Explanation: The array cannot be partitioned into equal sum subsets.
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 200
* 1 <= nums[i] <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	bool ans = false,res = false;

	nums = {1,5,11,5};
	ans = true;
	res = sol.canPartition(nums);
	println("ans : {} , res : {}",ans ,res);

	nums = {1,2,3,5};
	ans = false;
	res = sol.canPartition(nums);
	println("ans : {} , res : {}",ans ,res);

    return 0;
}
