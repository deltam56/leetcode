/**
* 3346. Maximum Frequency of an Element After Performing Operations I
* You are given an integer array nums and two integers k and numOperations.
* 
* You must perform an operation numOperations times on nums, where in each operation you:
* 
* Select an index i that was not selected in any previous operations.
* Add an integer in the range [-k, k] to nums[i].
* Return the maximum possible frequency of any element in nums after performing the operations.
* 
* 
* 
* Example 1:
* 
* Input: nums = [1,4,5], k = 1, numOperations = 2
* 
* Output: 2
* 
* Explanation:
* 
* We can achieve a maximum frequency of two by:
* 
* Adding 0 to nums[1]. nums becomes [1, 4, 5].
* Adding -1 to nums[2]. nums becomes [1, 4, 4].
* Example 2:
* 
* Input: nums = [5,11,20,20], k = 5, numOperations = 1
* 
* Output: 2
* 
* Explanation:
* 
* We can achieve a maximum frequency of two by:
* 
* Adding 0 to nums[1].
* 
* 
* Constraints:
* 
* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^5
* 0 <= k <= 10^5
* 0 <= numOperations <= nums.length
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
		// 일단 먼저 한번 자기값 자기가 가지고 있던놈들 추가하고
		// 바꿨을때 커버가능한 것들 갯수 추가하고
		//
        using int64 = long long;

        unordered_map<int64,int> base;
        base.reserve(nums.size()*2);
        for (int x : nums) base[x]++;

        map<int64,int64> diff;
        diff.clear();
        for (int x : nums) {
            int64 L = (int64)x - k;
            int64 R = (int64)x + k;
            diff[L] += 1;
            diff[R + 1] -= 1;
        }

        vector<int64> pts;
        pts.reserve(diff.size() + base.size());
        for (auto &p : diff) pts.push_back(p.first);
        for (auto &p : base)  pts.push_back(p.first);
        sort(pts.begin(), pts.end());
        pts.erase(unique(pts.begin(), pts.end()), pts.end());

        int ans = 1;
        for (auto &kv : base) ans = max(ans, kv.second); // 바꾸지 않아도 가능한 빈도

        int64 cover = 0;
        size_t di = 0; // diff 포인터 (diff는 map으로 정렬됨)
        auto itDiff = diff.begin();

        for (size_t i = 0; i < pts.size(); ++i) {
            int64 x = pts[i];

            while (itDiff != diff.end() && itDiff->first <= x) {
                cover += itDiff->second;
                ++itDiff;
            }

            auto itBase = base.find(x);
            if (itBase != base.end()) {
                int64 b = itBase->second;         // base[x]
                int64 c = cover;                  // cover[x]
                int64 canChange = max<int64>(0, c - b);
                int64 add = min<int64>(numOperations, canChange);
                ans = max<int>(ans, (int)(b + add));
            }

            if (i + 1 < pts.size()) {
                int64 nx = pts[i + 1];
                if (nx > x) {
                    int cand = (int)min<int64>(numOperations, cover);
                    ans = max(ans, cand);
                }
            } else {
            }
        }
        ans = min<int>(ans, (int)nums.size());
        return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	int k, numOperations;
	int ans,res;


	nums = {1,4,5};
	k = 1;
	numOperations = 2;
	ans = 2;
	res = sol.maxFrequency(nums,k,numOperations);
	println("ans : {}, res : {}",ans,res);

	nums = {5,11,20,20};
	k = 5;
	numOperations = 1;
	ans = 2;
	res = sol.maxFrequency(nums,k,numOperations);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
