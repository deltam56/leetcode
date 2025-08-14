/**
 * 3202. Find the Maximum Length of Valid Subsequence II
 * You are given an integer array nums and a positive integer k.
 * A subsequence sub of nums with length x is called valid if it satisfies:
 * 
 * (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
 * Return the length of the longest valid subsequence of nums.
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,4,5], k = 2
 * 
 * Output: 5
 * 
 * Explanation:
 * 
 * The longest valid subsequence is [1, 2, 3, 4, 5].
 * 
 * Example 2:
 * 
 * Input: nums = [1,4,2,3,1,4], k = 3
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The longest valid subsequence is [1, 4, 1, 4].
 * 
 * 
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 10^3
 * 1 <= nums[i] <= 10^7
 * 1 <= k <= 10^3
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int res = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                int prev_len = dp[j].count(mod) ? dp[j][mod] : 1;
                dp[i][mod] = max(dp[i][mod], prev_len + 1);

                res = max(res, dp[i][mod]);
            }
        }
        return res;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int k;
	int ans,res;

	nums = {1,2,3,4,5};
	k = 2;
	ans = 5;
	res = sol.maximumLength(nums,k);
	println("ans : {}, res :{}",ans,res);

	nums = {1,4,2,3,1,4};
	k = 3;
	ans = 4;
	res = sol.maximumLength(nums,k);
	println("ans : {}, res :{}",ans,res);

	return 0;
}
