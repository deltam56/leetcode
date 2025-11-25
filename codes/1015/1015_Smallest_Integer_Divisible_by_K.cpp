/**
 * 1015. Smallest Integer Divisible by K
 * Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
 * 
 * Return the length of n. If there is no such n, return -1.
 * 
 * Note: n may not fit in a 64-bit signed integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: k = 1
 * Output: 1
 * Explanation: The smallest answer is n = 1, which has length 1.
 * Example 2:
 * 
 * Input: k = 2
 * Output: -1
 * Explanation: There is no such positive integer n divisible by 2.
 * Example 3:
 * 
 * Input: k = 3
 * Output: 3
 * Explanation: The smallest answer is n = 111, which has length 3.
 * 
 * 
 * Constraints:
 * 
 * 1 <= k <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
	int smallestRepunitDivByK(int k) {
		// n 은 1 로만 이루어진 수
		// k 로 나누어 떨어져야함. 그 길이만 구하면 됨
		// 2나 5의 배수면 절대 나눌 수 없음
		if (k % 2 == 0 || k % 5 == 0) return -1;
		int rem = 0;
		for (int len = 1; len <= k; ++len) {
			rem = (rem * 10 + 1) % k; // 길이 len짜리 111...1 의 나머지
			if (rem == 0) return len;
		}
		return -1;
	}
};

int main() {
	Solution sol;
	int k;
	int ans,res;

	k = 1;
	ans = 1;
	res = sol.smallestRepunitDivByK(k);
	println("ans : {}, res : {}",ans,res);

	k = 2;
	ans = -1;
	res = sol.smallestRepunitDivByK(k);
	println("ans : {}, res : {}",ans,res);

	k = 3;
	ans = 3;
	res = sol.smallestRepunitDivByK(k);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
