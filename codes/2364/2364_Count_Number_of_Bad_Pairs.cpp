/*
2364. Count Number of Bad Pairs
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long gp = 0;
        long long totp = 0;
        int size = nums.size();
        unordered_map<int,int> count;
        for(int i=0;i<size;i++){
            totp += i;
            gp += count[nums[i]-i];
            count[nums[i]-i] += 1;
        }
        return totp-gp;
    }
};

void print(long long ans, long long res){
	cout << "ans : " << ans;
	cout << "   res : " << res;
	cout << endl;
	assert(ans == res);
	
}

int main() {
	Solution sol;	
	vector<int> nums;
	long long ans, res;


	nums = {4,1,3,3};
	ans = 5;
    res = sol.countBadPairs(nums);
	print(ans,res);

	nums = {1,2,3,4,5};
	ans = 0;
    res = sol.countBadPairs(nums);
	print(ans,res);



	cout << "Accepted!" <<endl;
    return 0;
}
