/*
   2342. Max Sum of a Pair With Equal Sum of Digits

   You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

   Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.



   Example 1:

   Input: nums = [18,43,36,13,7]
   Output: 54
   Explanation: The pairs (i, j) that satisfy the conditions are:
   - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
   - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
   So the maximum sum that we can obtain is 54.
   Example 2:

   Input: nums = [10,12,19,14]
   Output: -1
   Explanation: There are no two numbers that satisfy the conditions, so we return -1.


   Constraints:

   1 <= nums.length <= 10^5
   1 <= nums[i] <= 10^9


*/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <unordered_map>

using namespace std;
# if 0
class Solution {
public:
	inline int sumOfDigits(int num) { return (num == 0) ? 0 : (num % 10) + sumOfDigits(num / 10);}
	int maximumSum(vector<int>& nums) {
		int res=-1;
		for(int i=0;i<nums.size()-1; i++)
			for(int j=i+1;j<nums.size();j++)
				if(sumOfDigits(nums[i]) == sumOfDigits(nums[j]))
					res = max(res,nums[i]+nums[j]);
		return res;
	}
};

class Solution {
public:
	inline int sumOfDigits(int num) { return (num == 0) ? 0 : (num % 10) + sumOfDigits(num / 10);}
	int maximumSum(vector<int>& nums) {
		int res=-1;
		vector <int> sumdigs;
		for (int a : nums){
			int shard = sumOfDigits(a);
			auto it = find(sumdigs.begin(),sumdigs.end(),shard);
			if (it != sumdigs.end()){
				int index = distance(sumdigs.begin(), it);
				res = max(res,a+nums[index]);
			}
			sumdigs.push_back(shard);
		}
		return res;
	}
};
# endif

class Solution {
public:
	inline int sumOfDigits(int num) {
		int sum = 0;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}

	int maximumSum(vector<int>& nums) {
		int res = -1;
		unordered_map<int, int> maxNum; 

		for (int num : nums) {
			int digitSum = sumOfDigits(num);
			if (maxNum.count(digitSum)) {
				res = max(res, num + maxNum[digitSum]);

			}
			maxNum[digitSum] = max(maxNum[digitSum], num);
		}


		return res;
	}
};

int main() {
	Solution sol;
	vector <int> nums;
	int ans, res;

	nums = {18,43,36,13,7};
	ans = 54;
	res = sol.maximumSum(nums);
	println("ans : {} res : {}",ans,res);
	assert(ans ==res);

	nums = {10,12,19,14};
	ans = -1;
	res = sol.maximumSum(nums);
	println("ans : {} res : {}",ans,res);
	assert(ans ==res);

	cout << "Accepted!" <<endl;
	return 0;
}
