/**
* 1695. Maximum Erasure Value
* You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
* 
* Return the maximum score you can get by erasing exactly one subarray.
* 
* An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
* 
*  
* 
* Example 1:
* 
* Input: nums = [4,2,4,5,6]
* Output: 17
* Explanation: The optimal subarray here is [2,4,5,6].
* Example 2:
* 
* Input: nums = [5,2,1,2,5,2,1,2,5]
* Output: 8
* Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^4
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std; //편의성위해..
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        unordered_map<int, int> numcount;
        int sum = 0;
        int max_sum = 0;

        while (r < nums.size()) {
            int val = nums[r];
            sum += val;
            numcount[val]++;

            while (numcount[val] > 1) {
                sum -= nums[l];
                numcount[nums[l]]--;
                l++;
            }

            max_sum = max(max_sum, sum);
            r++;
        }

        return max_sum;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;
	nums = {10000};
	ans = 10000;
	res = sol.maximumUniqueSubarray(nums);
	println("ans: {} , res: {}",ans,res);

	nums = {4,2,4,5,6};
	ans = 17;
	res = sol.maximumUniqueSubarray(nums);
	println("ans: {} , res: {}",ans,res);

	nums = {5,2,1,2,5,2,1,2,5};
	ans = 8;
	res = sol.maximumUniqueSubarray(nums);
	println("ans: {} , res: {}",ans,res);

    return 0;
}
