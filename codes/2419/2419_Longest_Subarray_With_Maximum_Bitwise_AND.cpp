/**
* 2419. Longest Subarray With Maximum Bitwise AND
* You are given an integer array nums of size n.
* 
* Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
* 
* In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
* Return the length of the longest such subarray.
* 
* The bitwise AND of an array is the bitwise AND of all the numbers in it.
* 
* A subarray is a contiguous sequence of elements within an array.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,2,3,3,2,2]
* Output: 2
* Explanation:
* The maximum possible bitwise AND of a subarray is 3.
* The longest subarray with that value is [3,3], so we return 2.
* Example 2:
* 
* Input: nums = [1,2,3,4]
* Output: 1
* Explanation:
* The maximum possible bitwise AND of a subarray is 4.
* The longest subarray with that value is [4], so we return 1.
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
		int max_and = INT_MIN;
		int tmp_and = nums[0];
		int max_length = 0;

		int l = 0, r = 1;

		while(l <= r && r < nums.size()){
			tmp_and = nums[r] & tmp_and;
			if(tmp_and > max_and){
				max_and = tmp_and;
				max_length = (r) - l;
			}else{
				++l;
				tmp_and = nums[l];

			}
			++r;
		}
		return max_length;
    }
};
#else
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int max_len = 0;
        int curr_len = 0;

        for (int num : nums) {
            if (num == max_val) {
                ++curr_len;
                max_len = max(max_len, curr_len);
            } else {
                curr_len = 0;
            }
        }
        return max_len;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,2,3,3,2,2};
	ans = 2;
	res = sol.longestSubarray(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,2,3,4};
	ans = 1;
	res = sol.longestSubarray(nums);
	println("ans : {}, res : {}",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
