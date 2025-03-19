/**
 * 3191. Minimum Operations to Make Binary Array Elements Equal to One I
 * You are given a binary array nums.

 * You can do the following operation on the array any number of times (possibly zero):
 * 
 * Choose any 3 consecutive elements from the array and flip all of them.
 * Flipping an element means changing its value from 0 to 1, and from 1 to 0.
 * 
 * Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
 * 
 * Example 1:
 * 
 * Input: nums = [0,1,1,1,0,0]
 * 
 * Output: 3
 * 
 * Explanation:
 * We can do the following operations:
 * 
 * Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
 * Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
 * Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
 * Example 2:
 * 
 * Input: nums = [0,1,1,1]
 * 
 * Output: -1
 * 
 * Explanation:
 * It is impossible to make all elements equal to 1.
 * 
 *  
 * 
 * Constraints:
 * 
 * 3 <= nums.length <= 10^5
 * 0 <= nums[i] <= 1
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
public:
	int minOperations(vector<int>& nums) {
		int res = 0;
		int m = nums.size();
		for(int i = 0;i < m-2; i++){
			if(nums[i] == 0){
				nums[i] = !nums[i];
				nums[i+1] = !nums[i+1];
				nums[i+2] = !nums[i+2];
				res ++;
			}
		}
		if(nums[m-1] ==0 || nums[m-2]==0)
			return -1;

		return res;
	}
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans = 0;
	int res = 0;

	nums = {0,1,1,1,0,0};
	ans = 3;
	res = sol.minOperations(nums);
	println("ans : {} , res : {}", ans,res);
	assert(ans==res);

	nums = {0,1,1,1};
	ans = -1;
	res = sol.minOperations(nums);
	println("ans : {} , res : {}", ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
	return 0;
}
