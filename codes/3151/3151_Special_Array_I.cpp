/*
3151. Special Array I

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

 

Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int size = nums.size()-1;
        while(size>0){
            if(!((nums[size]%2)^(nums[size-1]%2)))
            {
                return false;
            }
            size--;
        }
        return true;
    }
};

void print(bool ans, bool ret){
	cout << "ans : " << ans;
	cout << "  ret : " << ret;
	cout << endl;

	assert(ans==ret);
}
int main() {

	Solution sol;
	vector<int> nums;
	bool ans,ret;

	

	nums = {1};
	ans = true;
	ret =	sol.isArraySpecial(nums);
	print(ans,ret);

	nums = {2,1,4};
	ans = true;
	ret =	sol.isArraySpecial(nums);
	print(ans,ret);


	nums = {4,3,1,6};
	ans = false;
	ret =	sol.isArraySpecial(nums);
	print(ans,ret);

	cout << "Accepted!" <<endl;
    return 0;
}
