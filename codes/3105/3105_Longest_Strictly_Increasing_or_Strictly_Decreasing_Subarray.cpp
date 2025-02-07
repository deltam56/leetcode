/*
3105. Longest Strictly Increasing or Strictly Decreasing Subarray

You are given an array of integers nums. Return the length of the longest
subarray
 of nums which is either
strictly increasing
 or
strictly decreasing
.



Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
class Solution{
public:
    int longestMonotonicSubarray(vector<int>& nums){
        int size = nums.size();
        int i = 1;
        int countregpos=0,countregneg=0,countpos=1,countneg=1;
        if (size ==1){
            return 1;
        }
        while (i < size){
            if (nums[i-1] <= nums[i]){
                countpos++;
                countneg = 1;
            }
            if(nums[i-1] >= nums[i]){
                countneg++;
                countpos = 1;
            }
            if ((nums[i-1]) == nums[i]){
                countpos=1;
                countneg=1;
            }
            if (countregpos < countpos){
                countregpos = countpos;
            }
            if (countregneg < countneg){
                countregneg = countneg;
            }
            i++;
        }
        if (countregneg > countregpos ){
            return countregneg;
        }else{
            return countregpos;
        }
    }
};
void print(int ans,int ret){
	cout << "ans  : " << ans;
	cout << "  ret : " << ret;
	cout << endl;
	assert(ans==ret);
}
int main(){

	Solution sol;
	vector <int> input;
	int ans=0;
	int ret=0;
	
	input =	{1,4,3,3,2};
	ans = 2;
	ret = sol.longestMonotonicSubarray(input);
	print(ans,ret);

	input =	{3,3,3,3};
	ans = 1;
	ret = sol.longestMonotonicSubarray(input);
	print(ans,ret);

	input =	{3,2,1};
	ans = 3;
	ret = sol.longestMonotonicSubarray(input);
	print(ans,ret);





	return 0;
}

