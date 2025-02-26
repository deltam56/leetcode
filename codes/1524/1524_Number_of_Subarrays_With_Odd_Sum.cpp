/**
 *
 * 1524. Number of Sub-arrays With Odd Sum
 *
 * 
 * Given an array of integers arr, return the number of subarrays with an odd sum.
 * 
 * Since the answer can be very large, return it modulo 109 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: arr = [1,3,5]
 * Output: 4
 * Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
 * All sub-arrays sum are [1,4,9,3,8,5].
 * Odd sums are [1,9,3,5] so the answer is 4.
 * Example 2:
 * 
 * Input: arr = [2,4,6]
 * Output: 0
 * Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
 * All sub-arrays sum are [2,6,12,4,10,6].
 * All sub-arrays have even sum and the answer is 0.
 * Example 3:
 * 
 * Input: arr = [1,2,3,4,5,6,7]
 * Output: 16
 * 
 * 
 * Constraints:
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 100
 * */

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
const int MOD = 1e9+7;
class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		// 누적 합이 짝수인 경우 (초기값: 아무것도 선택하지 않은 상태 포함)
		int even_count = 1;
		int odd_count = 0;  // 누적 합이 홀수인 경우
		int prefix_sum = 0;  // 누적 합
		int result = 0;  // 정답

		for (int num : arr){
			prefix_sum += num;

			if (prefix_sum % 2) {  // 현재까지의 합이 홀수인 경우
				result = (result + even_count) % MOD;  // 이전 짝수 개수만큼 더하기
				odd_count += 1;
			} else {  // 현재까지의 합이 짝수인 경우
				// 이전 홀수 개수만큼 더하기
				result = (result + odd_count) % MOD;
				even_count += 1;
			}
		}
		return result;
	}
};

int main() {
	Solution sol;	
	vector<int> arr;
	int ans, res;

	// prefix sum: 0   1   4  9
	// 1,      -> odd     res = 1
	// 1, 3,   -> even = even + even or odd + odd -> res = 1 
	// 1, 3, 5 -> odd = res + odd_cnt
	// ^^^^
	// 3
	// 3, 5    -> even
	// 5
	arr = {1,3,5};

	ans = 4;
	res = sol.numOfSubarrays(arr);
	println("ans = {} res = {} ",ans,res);
	assert(ans == res);

	arr = {2,4,6};
	ans = 0;
	res = sol.numOfSubarrays(arr);
	println("ans = {} res = {} ",ans,res);
	assert(ans == res);

	arr = {1,2,3,4,5,6,7};
	ans = 16;
	res = sol.numOfSubarrays(arr);
	println("ans = {} res = {} ",ans,res);
	assert(ans == res);

	cout << "Accepted!" <<endl;
    return 0;
}
