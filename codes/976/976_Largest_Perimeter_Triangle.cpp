/**
* 976. Largest Perimeter Triangle
* Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
* 
*  
* 
* Example 1:
* 
* Input: nums = [2,1,2]
* Output: 5
* Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
* Example 2:
* 
* Input: nums = [1,2,1,10]
* Output: 0
* Explanation: 
* You cannot use the side lengths 1, 1, and 2 to form a triangle.
* You cannot use the side lengths 1, 1, and 10 to form a triangle.
* You cannot use the side lengths 1, 2, and 10 to form a triangle.
* As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
*  
* 
* Constraints:
* 
* 3 <= nums.length <= 10^4
* 1 <= nums[i] <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 1; i >= 2; --i) {
            long long a = nums[i-2], b = nums[i-1], c = nums[i];
            if (a + b > c) {
                return (int)(a + b + c);
            }
        }
        return 0;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans, res;

	nums = {2,1,2};
	ans = 5;
	res = sol.largestPerimeter(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,2,1,10};
	ans = 0;
	res = sol.largestPerimeter(nums);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
