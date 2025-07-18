/**
 * 3201. Find the Maximum Length of Valid Subsequence I
 * You are given an integer array nums.
 * A subsequence sub of nums with length x is called valid if it satisfies:
 * 
 * (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
 * Return the length of the longest valid subsequence of nums.
 * 
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4]
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The longest valid subsequence is [1, 2, 3, 4].
 * 
 * Example 2:
 * 
 * Input: nums = [1,2,1,1,2,1,2]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * The longest valid subsequence is [1, 2, 1, 2, 1, 2].
 * 
 * Example 3:
 * 
 * Input: nums = [1,3]
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * The longest valid subsequence is [1, 3].
 * 
 * 
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 2 * 10^5
 * 1 <= nums[i] <= 10^7
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
    int maximumLength(vector<int>& nums) {
		int max_len = max(
            longestWithTargetParity(nums, 0),
            longestWithTargetParity(nums, 1)
        );

		return max_len;
    }

private:
    int longestWithTargetParity(const vector<int>& nums, int target_parity) {
        int max_len = 1;

        for (int i = 0; i < nums.size(); ++i) {
            int cur_len = 1;
            int prev = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if ((prev + nums[j]) % 2 == target_parity) {
                    cur_len++;
                    prev = nums[j];
                }
            }
            max_len = max(max_len, cur_len);
        }

        return max_len;
    }
};


int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,8,4,2,4};
	ans = 4;
	res = sol.maximumLength(nums);
	println("ans : {}, res : {}",ans,res);


	nums = {1,2,3,4};
	ans = 4;
	res = sol.maximumLength(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,2,1,1,2,1,2};
	ans = 6;
	res = sol.maximumLength(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,3};
	ans = 2;
	res = sol.maximumLength(nums);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
