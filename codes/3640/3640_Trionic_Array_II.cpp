/**
 * 3640. Trionic Array II
 * You are given an integer array nums of length n.
 * 
 * A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:
 * 
 * nums[l...p] is strictly increasing,
 * nums[p...q] is strictly decreasing,
 * nums[q...r] is strictly increasing.
 * Return the maximum sum of any trionic subarray in nums.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [0,-2,-1,-3,0,2,-1]
 * 
 * Output: -4
 * 
 * Explanation:
 * 
 * Pick l = 1, p = 2, q = 3, r = 5:
 * 
 * nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
 * nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
 * nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
 * Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
 * Example 2:
 * 
 * Input: nums = [1,4,2,7]
 * 
 * Output: 14
 * 
 * Explanation:
 * 
 * Pick l = 0, p = 1, q = 2, r = 3:
 * 
 * nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
 * nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
 * nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
 * Sum = 1 + 4 + 2 + 7 = 14.
 * 
 * 
 * Constraints:
 * 
 * 4 <= n = nums.length <= 105
 * -109 <= nums[i] <= 109
 * It is guaranteed that at least one trionic subarray exists.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        int i = 0;

        while (i < n - 1) {
            // 증가 구간 시작점 찾기
            while (i < n - 1 && nums[i] >= nums[i + 1]) i++;
            if (i >= n - 1) break;
            vector<pair<long long, long long>> inc;
            vector<pair<long long, long long>> dec;
            while (i < n - 1) {
                // 증가 구간 수집
                long long sum = nums[i];
                long long first = nums[i];
                while (i + 1 < n && nums[i] < nums[i + 1]) {
                    i++;
                    sum += nums[i];
                }
                inc.push_back({sum, first});
                // 감소가 바로 안 이어지면 이 그룹 종료
                if (i >= n - 1 || nums[i] <= nums[i + 1]) break;  // >= 를 <= 로 수정!
                // 감소 구간 수집
                sum = nums[i];
                first = nums[i];
                while (i + 1 < n && nums[i] > nums[i + 1]) {
                    i++;
                    sum += nums[i];
                }
                dec.push_back({sum, first});
                // 증가가 바로 안 이어지면 이 그룹 종료
                if (i >= n - 1 || nums[i] >= nums[i + 1]) break;  // 이건 맞음
            }
            // trionic 합 계산
            for (int j = 0; j < (int)dec.size() && j + 1 < (int)inc.size(); j++) {
                long long triSum = inc[j].first + dec[j].first + inc[j + 1].first
                                 - dec[j].second - inc[j + 1].second;
                ans = max(ans, triSum);
            }
        }
        return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int ans,res;

	nums = {1,4,2,2,3,1,2};
	ans = 8;
	res = sol.maxSumTrionic(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {0,-2,-1,-3,0,2,-1};
	ans = -4;
	res = sol.maxSumTrionic(nums);
	println("ans : {}, res : {}",ans,res);

	nums = {1,4,2,7};
	ans = 14;
	res = sol.maxSumTrionic(nums);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
