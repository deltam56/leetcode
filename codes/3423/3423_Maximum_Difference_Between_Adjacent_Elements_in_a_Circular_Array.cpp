/**
* 3423. Maximum Difference Between Adjacent Elements in a Circular Array
* Given a circular array nums, find the maximum absolute difference between adjacent elements.
* 
* Note: In a circular array, the first and last elements are adjacent.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,2,4]
* 
* Output: 3
* 
* Explanation:
* 
* Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
* 
* Example 2:
* 
* Input: nums = [-5,-10,-5]
* 
* Output: 5
* 
* Explanation:
* 
* The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.
* 
* 
* 
* Constraints:
* 
* 2 <= nums.length <= 100
* -100 <= nums[i] <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
		int back = nums.back();
		int ret = INT_MIN;
		vector<int> cirarray;
		cirarray.push_back(back);
		cirarray.insert(end(cirarray),begin(nums),end(nums));
		cirarray.push_back(nums[0]);

		for(int i = 0 ; i < cirarray.size()-1 ; ++i){
			ret = max(ret, abs(cirarray[i]-cirarray[i+1]));
		}
		return ret;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,2,4};
	ans = 3;
	res = sol.maxAdjacentDistance(nums);
	println("ans : {}, res :{}",ans, res);

	nums = {-5,-10,-5};
	ans = 5;
	res = sol.maxAdjacentDistance(nums);
	println("ans : {}, res :{}",ans, res);

	cout << "Accepted!" <<endl;
    return 0;
}
