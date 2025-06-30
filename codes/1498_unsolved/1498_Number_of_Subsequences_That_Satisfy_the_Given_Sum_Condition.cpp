/**
* 1498. Number of Subsequences That Satisfy the Given Sum Condition
* You are given an array of integers nums and an integer target.

* Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
* 
* 
* 
* Example 1:
* 
* Input: nums = [3,5,6,7], target = 9
* Output: 4
* Explanation: There are 4 subsequences that satisfy the condition.
* [3] -> Min value + max value <= target (3 + 3 <= 9)
* [3,5] -> (3 + 5 <= 9)
* [3,5,6] -> (3 + 6 <= 9)
* [3,6] -> (3 + 6 <= 9)
* Example 2:
* 
* Input: nums = [3,3,6,8], target = 10
* Output: 6
* Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
* [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
* Example 3:
* 
* Input: nums = [2,3,3,4,6,7], target = 12
* Output: 61
* Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
* Number of valid subsequences (63 - 2 = 61).
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^6
* 1 <= target <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>

using namespace std; //편의성위해..
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int res = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + pow2[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return res;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int target;
	int ans,res;

	nums = {3,5,6,7};
	target = 9;
	ans = 4;
	res = sol.numSubseq(nums, target);
	println("ans : {} , res :{}",ans,res);

	nums = {3,3,6,8};
	target = 10;
	ans = 6;
	res = sol.numSubseq(nums, target);
	println("ans : {} , res :{}",ans,res);

	nums = {2,3,3,4,6,7};
	target = 12;
	ans = 61;
	res = sol.numSubseq(nums, target);
	println("ans : {} , res :{}",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
