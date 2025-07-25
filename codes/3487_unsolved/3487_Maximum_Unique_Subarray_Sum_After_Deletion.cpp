/**
* 3487. Maximum Unique Subarray Sum After Deletion
* You are given an integer array nums.
* 
* You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
* 
* All elements in the subarray are unique.
* The sum of the elements in the subarray is maximized.
* Return the maximum sum of such a subarray.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,2,3,4,5]
* 
* Output: 15
* 
* Explanation:
* 
* Select the entire array without deleting any element to obtain the maximum sum.
* 
* Example 2:
* 
* Input: nums = [1,1,0,1,1]
* 
* Output: 1
* 
* Explanation:
* 
* Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.
* 
* Example 3:
* 
* Input: nums = [1,2,-1,-2,1,0,-1]
* 
* Output: 3
* 
* Explanation:
* 
* Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int maxSum(vector<int>& nums) {
		unordered_map<int,int> num_count;
		int l= 0, r = 0;
		int max_sum = INT_MIN;
		int sum = 0;
		if(nums.size()==1)
			return nums[0];
		while(r < nums.size()){
			sum += nums[r];
			num_count[nums[r]]++;
			while(num_count[nums[r]] > 1){
				num_count[nums[l]]--;
				sum -= nums[l];
				++l;
			}
			++r;
			max_sum = max(max_sum,sum);
		}
		while(l < r){
			sum -= nums[l];
			num_count[nums[l]]--;
			++l;
			max_sum = max(max_sum,sum);
		}
		return max_sum;
    }
};
#else
class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool allNegative = true;
        int maxVal = INT_MIN;

        for (int n : nums) {
            if (n >= 0) allNegative = false;
            if (n > maxVal) maxVal = n;
        }
        if (allNegative) return maxVal;

        unordered_set<int> unique(nums.begin(), nums.end());

        int sum = 0;
        for (int val : unique) {
            if (val > 0) sum += val;
        }

        return sum;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums ={-20,20};
	ans = 20;
	res = sol.maxSum(nums);
	println("ans : {}, res :{}", ans,res);

	nums ={-17,-15};
	ans = -15;
	res = sol.maxSum(nums);
	println("ans : {}, res :{}", ans,res);

	nums = {1,2,3,4,5};
	ans =15;
	res = sol.maxSum(nums);
	println("ans : {}, res :{}", ans,res);

	nums = {1,1,0,1,1};
	ans = 1;
	res = sol.maxSum(nums);
	println("ans : {}, res :{}", ans,res);

	nums = {1,2,-1,-2,1,0,-1};
	ans = 3;
	res = sol.maxSum(nums);
	println("ans : {}, res :{}", ans,res);

    return 0;
}
