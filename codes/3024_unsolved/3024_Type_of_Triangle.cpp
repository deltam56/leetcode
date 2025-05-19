/**
* 3024. Type of Triangle
* You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.
* 
* A triangle is called equilateral if it has all sides of equal length.
* A triangle is called isosceles if it has exactly two sides of equal length.
* A triangle is called scalene if all its sides are of different lengths.
* Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.
* 
* 
* 
* Example 1:
* 
* Input: nums = [3,3,3]
* Output: "equilateral"
* Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
* Example 2:
* 
* Input: nums = [3,4,5]
* Output: "scalene"
* Explanation:
* nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
* nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
* nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3.
* Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
* As all the sides are of different lengths, it will form a scalene triangle.
* 
* 
* Constraints:
* 
* nums.length == 3
* 1 <= nums[i] <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..
class Solution {
private:
	bool is_triangle(vector<int>& nums){
		if(nums[0] + nums[1] > nums[2] &&
		   nums[1] + nums[2] > nums[0] &&
		   nums[2] + nums[0] > nums[1])
			return true;
		return false;
	}
public:
    string triangleType(vector<int>& nums) {
		unordered_map<int,int> triangle_sides;

		if(!is_triangle(nums))
			return "none";
		for(int n: nums)
			triangle_sides[n]++;

		for(auto& it : triangle_sides){
			if(it.second > 2)
				return "equilateral";
			else if(it.second >1)
				return "isosceles";
		}


		return "scalene";


    }
};
int main() {
	Solution sol;
	vector<int> nums;
	string ans;
	string res;

	nums = {3,3,3};
	ans = "equilateral";
	res = sol.triangleType(nums);
	println("ans : {} , res : {}",ans,res);

	nums = {3,4,5};
	ans = "scalene";
	res = sol.triangleType(nums);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
