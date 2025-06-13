/**
* 2616. Minimize the Maximum Difference of Pairs
* You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
* 
* Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
* 
* Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
* 
* 
* 
* Example 1:
* 
* Input: nums = [10,1,2,7,1,3], p = 2
* Output: 1
* Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5.
* The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
* Example 2:
* 
* Input: nums = [4,2,1,2], p = 1
* Output: 0
* Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 105
* 0 <= nums[i] <= 109
* 0 <= p <= (nums.length)/2
**/
#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <queue>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
		priority_queue<int,vector<int>,greater<int>> sub_pairs_odd,sub_pairs_even;
		sort(nums.begin(),nums.end());

		for(int i = 1; i < nums.size() ; i++){
			if(i % 2 == 0)
				sub_pairs_even.push(abs(nums[i-1] - nums[i]));
			else
				sub_pairs_odd.push(abs(nums[i-1] - nums[i]));
		}

		int i = 1;
		while(i != p){
			sub_pairs_odd.pop();
			sub_pairs_even.pop();
			++i;
		}
		return max(sub_pairs_odd.top(),sub_pairs_even.top());


    }
};
#else
class Solution {
public:
    bool canFormPairs(const vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.back() - nums.front();

        while (left < right) {
            int mid = (left + right) / 2;
            if (canFormPairs(nums, p, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int p;
	int ans, res;

	nums = {10,1,2,7,1,3}, p = 2;
	ans = 1;
	res = sol.minimizeMax(nums,p);
	println("ans : {} , res : {}",ans,res);

	nums = {4,2,1,2}, p = 1;
	ans = 0;
	res = sol.minimizeMax(nums,p);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
