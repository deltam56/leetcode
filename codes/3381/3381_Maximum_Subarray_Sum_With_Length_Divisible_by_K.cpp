/**
 * 3381. Maximum Subarray Sum With Length Divisible by K
 * You are given an array of integers nums and an integer k.
 * 
 * Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2], k = 1
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.
 * 
 * Example 2:
 * 
 * Input: nums = [-1,-2,-3,-4,-5], k = 4
 * 
 * Output: -10
 * 
 * Explanation:
 * 
 * The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.
 * 
 * Example 3:
 * 
 * Input: nums = [-5,1,2,-3,4], k = 2
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.
 * 
 *  
 * 
 * Constraints:
 * 
 * 1 <= k <= nums.length <= 2 * 10^5
 * -10^9 <= nums[i] <= 10^9
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;
#if 0
class Solution {
public:
	long long maxSubarraySum(vector<int>& nums, int k) {
		int s = nums.size();
		long long ret = INT_MIN;
		vector<int> windows;
		int tmp = k;
		for(int i = 1; tmp < s ; i++){
			tmp = k*i;
			windows.push_back(tmp);
		}

		for(int winsize: windows){
			int l = 0;
			int r = winsize;
			long long sum = 0;
			for(int i = 0; i < r; i++)
				sum += nums[i];
			while(r < s){
				sum -= nums[l];
				l++;
				sum += nums[r];
				r++;;
				ret = max(ret, sum);
			}
			ret = max(ret,sum);
		}
		return ret;

	}
};
#else
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        const long long INF = (long long)4e18;

        // minPref[mod] = 지금까지 본 prefix들 중에서,
        // index % k == mod 인 prefix 값의 최소값
        vector<long long> minPref(k, INF);

        long long prefix = 0;
        long long ans = numeric_limits<long long>::min();

        // prefix[0] = 0, index 0 % k = 0
        minPref[0] = 0;

        for (int i = 1; i <= n; ++i) {
            prefix += nums[i - 1];
            int mod = i % k;

            // 같은 mod 를 가진 이전 prefix 들이 있다면,
            // 길이가 k 로 나누어 떨어지는 subarray 하나 만들 수 있음
            if (minPref[mod] != INF) {
                ans = max(ans, prefix - minPref[mod]);
            }

            // 이 mod 에 대한 최소 prefix 갱신
            if (prefix < minPref[mod]) {
                minPref[mod] = prefix;
            }
        }

        return ans;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	int k;
	int ans,res;

	nums = {1,2}, k = 1;
	ans = 3;
	res = sol.maxSubarraySum(nums,k);
	println("ans : {}, res : {}",ans,res);

	nums = {-1,-2,-3,-4,-5}, k = 4;
	ans = -10;
	res = sol.maxSubarraySum(nums,k);
	println("ans : {}, res : {}",ans,res);

	nums = {-5,1,2,-3,4}, k = 2;
	ans = 4;
	res = sol.maxSubarraySum(nums,k);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
