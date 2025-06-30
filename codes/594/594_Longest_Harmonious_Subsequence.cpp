/**
* 594. Longest Harmonious Subsequence
* We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
* 
* Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,3,2,2,5,2,3,7]
* 
* Output: 5
* 
* Explanation:
* 
* The longest harmonious subsequence is [3,2,2,2,3].
* 
* Example 2:
* 
* Input: nums = [1,2,3,4]
* 
* Output: 2
* 
* Explanation:
* 
* The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.
* 
* Example 3:
* 
* Input: nums = [1,1,1,1]
* 
* Output: 0
* 
* Explanation:
* 
* No harmonic subsequence exists.
* 
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 2 * 10^4
* -109 <= nums[i] <= 10^9
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
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int maxLen = 0;
        for (auto& [num, cnt] : count) {
            if (count.count(num + 1)) {
                maxLen = max(maxLen, cnt + count[num + 1]);
            }
        }
        return maxLen;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,3,2,2,5,2,3,7};
	ans = 5;
	res = sol.findLHS(nums);
	println("ans : {} , res : {}",ans,res);

	nums = {1,2,3,4};
	ans = 2;
	res = sol.findLHS(nums);
	println("ans : {} , res : {}",ans,res);

	nums = {1,1,1,1};
	ans = 0;
	res = sol.findLHS(nums);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
