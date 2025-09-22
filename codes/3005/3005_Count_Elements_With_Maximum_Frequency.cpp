/**
* 3005. Count Elements With Maximum Frequency
* You are given an array nums consisting of positive integers.
* 
* Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
* 
* The frequency of an element is the number of occurrences of that element in the array.
* 
*  
* 
* Example 1:
* 
* Input: nums = [1,2,2,3,1,4]
* Output: 4
* Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
* So the number of elements in the array with maximum frequency is 4.
* Example 2:
* 
* Input: nums = [1,2,3,4,5]
* Output: 5
* Explanation: All elements of the array have a frequency of 1 which is the maximum.
* So the number of elements in the array with maximum frequency is 5.
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 100
* 1 <= nums[i] <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
		unordered_map<int,int> freq;
		vector<int> sum_freq(101,0);
		int max_freq = 0;
		for(int i : nums){
			if(freq[i] > 0)
				if(sum_freq[freq[i]] > 0)
					sum_freq[freq[i]]--;
			freq[i]++;
			max_freq = max(max_freq,freq[i]);
			sum_freq[freq[i]]++;
		}
		return sum_freq[max_freq]*max_freq;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,2,2,3,1,4};
	ans = 4;
	res = sol.maxFrequencyElements(nums);
	println("ans : {} , res : {}",ans,res);

	nums = {1,2,3,4,5};
	ans = 5;
	res = sol.maxFrequencyElements(nums);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
