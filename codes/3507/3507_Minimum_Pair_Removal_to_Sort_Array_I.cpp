/**
* 3507. Minimum Pair Removal to Sort Array I
* Given an array nums, you can perform the following operation any number of times:
*
* Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
* Replace the pair with their sum.
* Return the minimum number of operations needed to make the array non-decreasing.
* 
* An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
* 
* 
* 
* Example 1:
* 
* Input: nums = [5,2,3,1]
* 
* Output: 2
* 
* Explanation:
* 
* The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
* The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
* The array nums became non-decreasing in two operations.
* 
* Example 2:
* 
* Input: nums = [1,2,2]
* 
* Output: 0
* 
* Explanation:
* 
* The array nums is already sorted.
* 
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 50
* -1000 <= nums[i] <= 1000
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(!is_sorted(nums.begin(), nums.end())) {
            int minIdx = 0;
            int minSum = nums[0] + nums[1];
            for(int i = 1; i < nums.size() - 1; ++i) {
                int sumnum = nums[i] + nums[i+1];
                if(sumnum < minSum) {
                    minSum = sumnum;
                    minIdx = i;
                }
            }
            nums[minIdx] = minSum;
            nums.erase(nums.begin() + minIdx + 1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {5,2,3,1};
	ans = 2;
	res = sol.minimumPairRemoval(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,2,2};
	ans = 0;
	res = sol.minimumPairRemoval(nums);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
