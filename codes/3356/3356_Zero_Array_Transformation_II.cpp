/**
* 3356. Zero Array Transformation II
* You are given an integer array nums of length n and a 2D array queries where queries{i} = {li, ri, vali}.

* Each queries{i} represents the following action on nums:
* 
* - Decrement the value at each index in the range {li, ri} in nums by at most vali.
* - The amount by which each value is decremented can be chosen independently for each index.
* A Zero Array is an array with all its elements equal to 0.
* 
* Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
* 
*  
* 
* Example 1:
* 
* Input: nums = {2,0,2}, queries = {{0,2,1},{0,2,1},{1,1,3}}
* 
* Output: 2
* 
* Explanation:
* 
* For i = 0 (l = 0, r = 2, val = 1):
* Decrement values at indices {0, 1, 2} by {1, 0, 1} respectively.
* The array will become {1, 0, 1}.
* For i = 1 (l = 0, r = 2, val = 1):
* Decrement values at indices {0, 1, 2} by {1, 0, 1} respectively.
* The array will become {0, 0, 0}, which is a Zero Array. Therefore, the minimum value of k is 2.
* Example 2:
* 
* Input: nums = {4,3,2,1}, queries = {{1,3,2},{0,2,1}}
* 
* Output: -1
* 
* Explanation:
* 
* For i = 0 (l = 1, r = 3, val = 2):
* Decrement values at indices {1, 2, 3} by {2, 2, 1} respectively.
* The array will become {4, 1, 0, 0}.
* For i = 1 (l = 0, r = 2, val = 1):
* Decrement values at indices {0, 1, 2} by {1, 1, 0} respectively.
* The array will become {3, 0, 0, 0}, which is not a Zero Array.
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 0 <= nums{i} <= 5 * 10^5
* 1 <= queries.length <= 10^5
* queries{i}.length == 3
* 0 <= li <= ri < nums.length
* 1 <= vali <= 5
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <functional>
using namespace std; //편의성위해..

#if 0 // bruteforce  ( TLE )
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0;
		int m = nums.size();
		for (auto& current: queries){
			bool zerocheck = true;
			for (int i = 0 ; i < m ; i++){
				if (nums[i] <= 0)
					continue;
				else
					zerocheck = false;

				if( i >= current[0] && i<= current[1])
					nums[i] = nums[i] - current[2];
			}
			if(zerocheck == false){
				res ++;
			} else {
				break;
			}
		}
		for(int num: nums)
			if(num >0)
				return -1;
		return res;
    }
};
class Solution { // TLE neither
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0;
		for (auto& current: queries){
            if (all_of(nums.begin(), nums.end(), [](int x) {
				return x <= 0;
			})) {
                return res;
            }
			int l = current[0], r = current[1], v = current[2];
			transform(nums.begin() + l, nums.begin() + r + 1,
					  nums.begin() + l,
					  [v](int a) { return a - v; });
            res++;
		}
		for(int num: nums)
			if(num >0)
				return -1;
		return res;
    }
};
#else
class Solution {  // binary search and 차분배열
public:
    bool canMakeZero(vector<int> nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // 차분 배열 초기화

        // `k`개의 쿼리만 적용
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], v = queries[i][2];
            diff[l] -= v;
            if (r + 1 < n) diff[r + 1] += v;
        }

        // 차분 배열을 적용하여 `nums` 업데이트
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            nums[i] += sum;
            if (nums[i] > 0) return false; // 아직 0이 안 되면 실패
        }

        return true; // nums가 모두 0 이하로 변환됨
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size();
        int result = -1;

        // 바이너리 서치 적용
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canMakeZero(nums, queries, mid)) {
                result = mid;
                high = mid - 1; // 더 작은 k를 찾기 위해 탐색 범위를 줄임
            } else {
                low = mid + 1; // 더 많은 쿼리를 적용해야 하므로 탐색 범위 증가
            }
        }

        return result;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	vector<vector<int>> queries;
	int ans = 0;
	int res = 0;

	nums = {7,6,8};
	queries = {{0,0,2},{0,1,5},{2,2,5},{0,2,4}};
	ans = 4;
	res = sol.minZeroArray(nums,queries);
	println("ans : {}  res : {}", ans, res);
	assert(ans == res);

	nums = {2,0,2};
	queries = {{0,2,1},{0,2,1},{1,1,3}};
	ans = 2;
	res = sol.minZeroArray(nums,queries);
	println("ans : {}  res : {}", ans, res);
	assert(ans == res);

	nums = {4,3,2,1};
	queries = {{1,3,2},{0,2,1}};
	ans = -1;
	res = sol.minZeroArray(nums,queries);
	println("ans : {}  res : {}", ans, res);
	assert(ans == res);

	cout << "Accepted!" <<endl;
    return 0;
}
