/**
 * 3318. Find X-Sum of All K-Long Subarrays I
 * *You are given an array nums of n integers and two integers k and x.
 * 
 * The x-sum of an array is calculated by the following procedure:
 * 
 * Count the occurrences of all elements in the array.
 * Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 * Calculate the sum of the resulting array.
 * Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 * 
 * Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 * 
 * Output: [6,10,12]
 * 
 * Explanation:
 * 
 * For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 * For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 * For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 * Example 2:
 * 
 * Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 * 
 * Output: [11,15,15,15,12]
 * 
 * Explanation:
 * 
 * Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 * 
 *  
 * 
 * Constraints:
 * 
 * 1 <= n == nums.length <= 50
 * 1 <= nums[i] <= 50
 * 1 <= x <= k <= nums.length
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
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int MAXV = 50;
        int n = (int)nums.size();
        vector<array<int, 51>> pref(n + 1);
        pref[0].fill(0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i];
            pref[i + 1][nums[i]]++;
        }

        vector<int> ans;
        ans.reserve(n - k + 1);

        for (int l = 0; l + k <= n; ++l) {
            int r = l + k;
            vector<pair<int,int>> items;
            items.reserve(50);
            for (int v = 1; v <= MAXV; ++v) {
                int f = pref[r][v] - pref[l][v];
                if (f > 0) items.emplace_back(f, v);
            }

            sort(items.begin(), items.end(), [](const auto& a, const auto& b){
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });

            long long sum = 0;
            int take = min<int>(x, (int)items.size());
            for (int i = 0; i < take; ++i) {
                sum += 1LL * items[i].first * items[i].second;
            }
            ans.push_back((int)sum);
        }
        return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int k,x;
	vector<int> ans,res;

	nums = {1,1,2,2,3,4,2,3}, k = 6, x = 2;
	ans = {6,10,12};
	res = sol.findXSum(nums,k,x);
	println("ans : {}, res : {}",ans, res);

	nums = {3,8,7,8,7,5}, k = 2, x = 2;
	ans = {11,15,15,15,12};
	res = sol.findXSum(nums,k,x);
	println("ans : {}, res : {}",ans, res);

	return 0;
}
