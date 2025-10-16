/**
 * 3350. Adjacent Increasing Subarrays Detection II
 * Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:
 * 
 * Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
 * The subarrays must be adjacent, meaning b = a + k.
 * Return the maximum possible value of k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [2,5,7,8,9,2,3,4,3,1]
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
 * The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
 * These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
 * Example 2:
 * 
 * Input: nums = [1,2,3,4,4,4,4,5,6,7]
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * The subarray starting at index 0 is [1, 2], which is strictly increasing.
 * The subarray starting at index 2 is [3, 4], which is also strictly increasing.
 * These two subarrays are adjacent, and 2 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.
 * 
 * 
 * Constraints:
 * 
 * 2 <= nums.length <= 2 * 10^5
 * -10^9 <= nums[i] <= 10^9
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
/*
class Solution {
public:
	int maxIncreasingSubarrays(vector<int>& nums) {
		//조건 보면 n^2 으로는 안됨
		//가장 긴 증가 구간을 찾음 (max), 처음 - l, 끝(처음+l) + l 까지 양옆을 봄
		//맞으면 return l
		//l bsearch 하면서 봄 (일단 먼저 -- 부터 구현 후 변경)

		int l = 1;
		map<int,vector<int>> lindex;
		unordered_map<int,int> maxlengthbyindex;
		int maxleng = 0;

		for(int i = 0; i < nums.size()-1; i++){
			l = 1;
			for(int j = i+1;  j < nums.size()&&nums[j-1] < nums[j]; ++j){
				l++;
			}
			if(l > 1){
				lindex[l].push_back(i);
				maxlengthbyindex[i] = max(maxlengthbyindex[i], l);
				maxleng = max(maxleng,l);
			}
		}
		// 뒤에서 부터 순회하며, 붙어있는지를 체크
		for(auto it = lindex.rbegin(); it != lindex.rend(); it++){
			int leng = it->first;

			for(int i : it->second){
				if(maxlengthbyindex[i+leng] >= leng)
					return max(maxleng/2,leng);
			}
		}
		return max(maxleng/2, 1);
	}
};
*/
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        vector<int> L(n, 1), R(n, 1);

        // L[i]: i에서 끝나는 증가 길이
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] < nums[i]) L[i] = L[i-1] + 1;
        }

        // R[i]: i에서 시작하는 증가 길이
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) R[i] = R[i+1] + 1;
        }

        int ans = 0;
        // 경계 i | i+1 기준으로 최대 k 갱신
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, min(L[i], R[i+1]));
        }
        return ans;
    }
};
int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums ={-16,-13,-4,9,17,20,-6,8};
	ans = 3;
	res = sol.maxIncreasingSubarrays(nums);
	println("ans : {}, res : {}",ans,res);


	nums = {2,5,7,8,9,2,3,4,3,1};
	ans = 3;
	res = sol.maxIncreasingSubarrays(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,2,3,4,4,4,4,5,6,7};
	ans = 2;
	res = sol.maxIncreasingSubarrays(nums);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
