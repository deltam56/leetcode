/**
* 611. Valid Triangle Number
* Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
* 
* 
* 
* Example 1:
* 
* Input: nums = [2,2,3,4]
* Output: 3
* Explanation: Valid combinations are:
* 2,3,4 (using the first 2)
* 2,3,4 (using the second 2)
* 2,2,3
* Example 2:
* 
* Input: nums = [4,2,3,4]
* Output: 4
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 1000
* 0 <= nums[i] <= 1000
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>

using namespace std;
#if 0
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		// 내림 정렬
		// 가장 큰값 -> 다음값 + 다다음값 가능?
		int count = 0;
		sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});

		for(int i = 0 ; i < nums.size(); ++i){
			for(int j = i+1 ; j < nums.size(); ++j){
				for(int k = j+1; k < nums.size(); ++k){
					if(nums[i] >= nums[j]+nums[k]) break;
					count ++;
				}
			}
		}
		return count;
    }
};
#else
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		// 내림 정렬
		// 가장 큰값 -> 다음값 + 다다음값 가능?
		int count = 0;
		sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});

		for(int i = 0 ; i < nums.size(); ++i){
			for(int j = i+1 ; j < nums.size(); ++j){
				for(int k = j+1; k < nums.size(); ++k){
					if(nums[i] >= nums[j]+nums[k]) break;
					count ++;
				}
			}
		}
		return count;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {2,2,3,4};
	ans = 3;
	res = sol.triangleNumber(nums);
	println("ans : {} , res : {}",ans,res);

	nums = {4,2,3,4};
	ans = 4;
	res = sol.triangleNumber(nums);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
