/**
* 2654. Minimum Number of Operations to Make All Array Elements Equal to 1
* You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
* 
* Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
* Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
* 
* The gcd of two integers is the greatest common divisor of the two integers.
* 
* 
* 
* Example 1:
* 
* Input: nums = [2,6,3,4]
* Output: 4
* Explanation: We can do the following operations:
* - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
* - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
* - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
* - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
* Example 2:
* 
* Input: nums = [2,10,6,14]
* Output: -1
* Explanation: It can be shown that it is impossible to make all the elements equal to 1.
* 
* 
* Constraints:
* 
* 2 <= nums.length <= 50
* 1 <= nums[i] <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
		// 가능 불가능 여부는 gcd(nums) == 1 인지 가지고 판단 (다변수 gcd)
        int n = nums.size();
		int best = INT_MAX;
		int g = 0;

		//초기 판단
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;
        for (int x : nums) g = std::gcd(g, x);
        if (g != 1) return -1;

        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) {
                cur = std::gcd(cur, nums[j]);
                if (cur == 1) {
                    best = min(best, j - i + 1);
                    break;
                }
            }
        }
        return (best - 1) + (n - 1); // n + best - 2;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {2,6,3,4};
	ans = 4;
	res = sol.minOperations(nums);
	println("ans : {}, res : {}",ans,res);


	nums = {2,10,6,14};
	ans = -1;
	res = sol.minOperations(nums);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
