/**
*
* 873. Length of Longest Fibonacci Subsequence
* A sequence x1, x2, ..., xn is Fibonacci-like if:
* 
* - n >= 3
* - xi + xi+1 == xi+2 for all i + 2 <= n
* Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
* 
* A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
* 
*  
* 
* Example 1:
* 
* Input: arr = [1,2,3,4,5,6,7,8]
* Output: 5
* Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
* Example 2:
* 
* Input: arr = [1,3,7,11,12,14,18]
* Output: 3
* Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
*  
* 
*
* Constraints:
* 
* 3 <= arr.length <= 1000
* 1 <= arr[i] < arr[i + 1] <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		const int n = arr.size();
		unordered_set<int> hset(begin(arr), end(arr));
		int res = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int a = arr[i];
				int b = arr[j];
				int len = 2;

				while (hset.count(a + b)) {
					b = a + b;   // b = 3 + 5 = 8
					a = b - a;   // a = 8 - 3 = 5
					len++;
					println("a : {} b : {}  a+b : {} len : {}",a,b,a+b,len);
				}
				res = max(res, len);
			}
		}

		return res > 2 ? res : 0;
	}
};
#else
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		const int n = arr.size();
		// {arr[index] : index}
		unordered_map<int, int> hmap;
		/*
		 * dp[i][j]
		 *  - the longest length of fibonacci sequences between arr[i] and
		 *    arr[j]
		 *  - dp[i][j] = dp[j - i][i] + 1
		 */
		vector<vector<int>> dp(n, vector<int>(n, 0));
		int res = 0;

		for (int j = 0; j < n; ++j) {
			hmap[arr[j]] = j;

			for (int i = 0; i < j; ++i) {
				int idx = -1;

				if (hmap.find(arr[j] - arr[i]) != hmap.end())
					idx = hmap[arr[j] - arr[i]];

				dp[i][j] = (arr[j] - arr[i] < arr[i] and idx != -1) ?
					dp[idx][i] + 1 : 2;

				res = max(res, dp[i][j]);
			}
		}

		return res > 2 ? res : 0;

	}
};
#endif
int main() {
	Solution sol;	
	vector<int> arr;
	int ans,res;

	arr = {1,2,3,4,5,6,7,8};
	ans = 5;
	res = sol.lenLongestFibSubseq(arr);
	println("ans = {}, res = {}",ans,res);
	assert(ans==res);

	arr = {1,3,7,11,12,14,18};
	ans = 3;
	res = sol.lenLongestFibSubseq(arr);
	println("ans = {}, res = {}",ans,res);
	assert(ans==res);

	arr = {2,4,7,8,9,10,14,15,18,23,32,50};
	ans = 5;
	res = sol.lenLongestFibSubseq(arr);
	println("ans = {}, res = {}",ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
    return 0;
}
