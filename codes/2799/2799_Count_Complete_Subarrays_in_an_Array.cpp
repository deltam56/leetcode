/**
 * 2799. Count Complete Subarrays in an Array
 * You are given an array nums consisting of positive integers.
 * 
 * We call a subarray of an array complete if the following condition is satisfied:
 * 
 * The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
 * Return the number of complete subarrays.
 * 
 * A subarray is a contiguous non-empty part of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,3,1,2,2]
 * Output: 4
 * Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
 * Example 2:
 * 
 * Input: nums = [5,5,5,5]
 * Output: 10
 * Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 * 
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2000
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std; //편의성위해..
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        // 전체에서 unique한 숫자의 개수를 구함
        unordered_map<int, int> uniqueCount;
        for (int num : nums) {
            uniqueCount[num]++;
        }
        int required = uniqueCount.size();

        // 슬라이딩 윈도우로 complete subarray 개수 세기
        for (int l = 0; l < n; ++l) {
            unordered_map<int, int> windowCount;
            for (int r = l; r < n; ++r) {
                windowCount[nums[r]]++;
                if (windowCount.size() == required) {
                    count++;
                }
            }
        }

        return count;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int ans = 0, res = 0;

	nums = {1,3,1,2,2};
	ans = 4;
	res = sol.countCompleteSubarrays(nums);
	println("ans : {}, res : {} ",ans,res);
	nums = {5,5,5,5};
	ans = 10;
	res = sol.countCompleteSubarrays(nums);
	println("ans : {}, res : {} ",ans,res);

	cout << "Accepted!" <<endl;
	return 0;
}
