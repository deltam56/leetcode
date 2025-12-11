/**
* 3583. Count Special Triplets
* You are given an integer array nums.
* 
* A special triplet is defined as a triplet of indices (i, j, k) such that:
* 
* 0 <= i < j < k < n, where n = nums.length
* nums[i] == nums[j] * 2
* nums[k] == nums[j] * 2
* Return the total number of special triplets in the array.
* 
* Since the answer may be large, return it modulo 109 + 7.
* 
* 
* 
* Example 1:
* 
* Input: nums = [6,3,6]
* 
* Output: 1
* 
* Explanation:
* 
* The only special triplet is (i, j, k) = (0, 1, 2), where:
* 
* nums[0] = 6, nums[1] = 3, nums[2] = 6
* nums[0] = nums[1] * 2 = 3 * 2 = 6
* nums[2] = nums[1] * 2 = 3 * 2 = 6
* Example 2:
* 
* Input: nums = [0,1,0,0]
* 
* Output: 1
* 
* Explanation:
* 
* The only special triplet is (i, j, k) = (0, 2, 3), where:
* 
* nums[0] = 0, nums[2] = 0, nums[3] = 0
* nums[0] = nums[2] * 2 = 0 * 2 = 0
* nums[3] = nums[2] * 2 = 0 * 2 = 0
* Example 3:
* 
* Input: nums = [8,4,2,8,4]
* 
* Output: 2
* 
* Explanation:
* 
* There are exactly two special triplets:
* 
* (i, j, k) = (0, 1, 3)
* nums[0] = 8, nums[1] = 4, nums[3] = 8
* nums[0] = nums[1] * 2 = 4 * 2 = 8
* nums[3] = nums[1] * 2 = 4 * 2 = 8
* (i, j, k) = (1, 2, 4)
* nums[1] = 4, nums[2] = 2, nums[4] = 4
* nums[1] = nums[2] * 2 = 2 * 2 = 4
* nums[4] = nums[2] * 2 = 2 * 2 = 4
* 
* 
* Constraints:
* 
* 3 <= n == nums.length <= 105
* 0 <= nums[i] <= 105
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
using namespace std;
#if 0
class Solution {
private:
	const int MOD = 1e9+7;
public:
    int specialTriplets(vector<int>& nums) {
		long long cnt = 0;
		unordered_map<int,int> idxs;
		unordered_map<int,int> tmpsums;
		for(int i = 0 ;i < nums.size(); ++i){
			idxs[nums[i]]++;
			int mulnum = nums[i]*2;
			if(idxs[nums[i]] %2 ==0){
				cnt += tmpsums[idxs[nums[i]]];
				tmpsums[idxs[nums[i]]] = 0;
			}
			if(idxs[mulnum] %2 == 1){
				tmpsums[mulnum]++;
			}
		}
		return cnt % MOD;
    }
};
#else

class Solution {
private:
    static const int MOD = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3) return 0;

        int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        vector<long long> left(maxVal + 1, 0), right(maxVal + 1, 0);

        for (int x : nums) {
            right[x]++;
        }

        long long ans = 0;

        for (int j = 0; j < n; ++j) {
            int v = nums[j];
            right[v]--;

            long long twice = 1LL * v * 2;
            if (twice <= maxVal) {
                long long L = left[twice];   // i < j, nums[i] == 2*nums[j]
                long long R = right[twice];  // k > j, nums[k] == 2*nums[j]

                ans = (ans + (L % MOD) * (R % MOD)) % MOD;
            }
            left[v]++;
        }

        return (int)ans;
    }
};;
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {6,3,6};
	ans = 1;
	res = sol.specialTriplets(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {0,1,0,0};
	ans = 1;
	res = sol.specialTriplets(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {8,4,2,8,4};
	ans = 2;
	res = sol.specialTriplets(nums);
	println("ans : {}, res : {}",ans,res);
	
    return 0;
 }
