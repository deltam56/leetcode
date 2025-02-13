/*
   3066. Minimum Operations to Exceed Threshold Value II
   You are given a 0-indexed integer array nums, and an integer k.

   In one operation, you will:

   Take the two smallest integers x and y in nums.
   Remove x and y from nums.
   Add min(x, y) * 2 + max(x, y) anywhere in the array.
   Note that you can only apply the described operation if nums contains at least two elements.

   Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.



   Example 1:

   Input: nums = [2,11,10,1,3], k = 10
   Output: 2
   Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
   In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
   At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
   It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
   Example 2:

   Input: nums = [1,1,2,4,9], k = 20
   Output: 4
   Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
   After two operations, nums becomes equal to [7, 4, 9].
   After three operations, nums becomes equal to [15, 9].
   After four operations, nums becomes equal to [33].
   At this stage, all the elements of nums are greater than 20 so we can stop.
   It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.


   Constraints:

   2 <= nums.length <= 2 * 10^5
   1 <= nums[i] <= 10^9
   1 <= k <= 10^9
   The input is generated such that an answer always exists. That is, there exists some sequence of operations after which all elements of the array are greater than or equal to k.

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <print>

using namespace std;

class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		long sums=0;
		int count=0;
		long m1 = 0 , m2 = 0;
		priority_queue <long,vector<long>,greater<long>> ordered_num;
		for (int i = 0; i < nums.size(); ++i) {
			ordered_num.push(nums[i]);
		}
		while(ordered_num.top() < k){
			count++;
			m1 = ordered_num.top();
			ordered_num.pop();
			m2 = ordered_num.top();
			ordered_num.pop();
			sums = (m1*2) + m2;
			ordered_num.push(sums);
		}
		return count;
	}
};

#if 0
#include <queue>

struct {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
} comp;

class Solution {
public:
	int minOperations(vector<int>& nums, int k) {
		int cnt = 0;
		//priority_queue<int, vector<int>, greater<int>> min_heap;
/*
		auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>,
			decltype(comp)> min_heap(comp);
*/

		for (int& num : nums)
			min_heap.push(num);

		while (!min_heap.empty() and min_heap.top() < k) {
			int f = min_heap.top();
			min_heap.pop();
			int s = min_heap.top();
			min_heap.pop();

			min_heap.push(f * 2 + s);
			cnt++;
		}

		return cnt;
	}
};
#endif

int main() {
	Solution sol;	
	vector <int> nums;
	int k;
	int ans,res;


	nums = {2,11,10,1,3};
	k = 10;
	ans = 2;
	res = sol.minOperations(nums,k);
	println("nums : {}  k : {}",nums,k);
	println("ans : {}  res : {}",ans,res);
	assert(ans == res);


	nums = {1,1,2,4,9};
	k = 20;
	ans = 4;
	res = sol.minOperations(nums,k);
	println("nums : {}  k : {}",nums,k);
	println("ans : {}  res : {}",ans,res);
	assert(ans == res);

	cout << "Accepted!" <<endl;
	return 0;
}
