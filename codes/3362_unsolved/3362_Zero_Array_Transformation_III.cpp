/**
 * 3362. Zero Array Transformation III
 * You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
 * 
 * Each queries[i] represents the following action on nums:
 * 
 * Decrement the value at each index in the range [li, ri] in nums by at most 1.
 * The amount by which the value is decremented can be chosen independently for each index.
 * A Zero Array is an array with all its elements equal to 0.
 * 
 * Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
 * 
 * Output: 1
 * 
 * Explanation:
 * 
 * After removing queries[2], nums can still be converted to a zero array.
 * 
 * Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 * Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 * Example 2:
 * 
 * Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * We can remove queries[2] and queries[3].
 * 
 * Example 3:
 * 
 * Input: nums = [1,2,3,4], queries = [[0,3]]
 * 
 * Output: -1
 * 
 * Explanation:
 * 
 * nums cannot be converted to a zero array even after using all the queries.
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= li <= ri < nums.length
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std; //편의성위해..
#if 0 //MLE 난 버전
class Solution {
private:
	vector<int> solNums;
	vector<vector<int>> solQueries;
	int Maxcount = 0;

	void dfs(vector<vector<int>>& subQueries, int next) {
		if (next == solQueries.size()) {
			if (canZeroArray(subQueries)) {
				Maxcount = max(Maxcount, static_cast<int>(solQueries.size()
														  - subQueries.size()));
			}
			return;
		}
		dfs(subQueries, next + 1);
		subQueries.push_back(solQueries[next]);
		dfs(subQueries, next + 1);
		subQueries.pop_back();
	}

	bool canZeroArray(vector<vector<int>>& subQueries){
		int m = solNums.size();
		int q = subQueries.size();
		vector<int> diff(m+1, 0);

		for(int i = 0; i < q; ++i){
			diff[subQueries[i][0]]++;
			diff[subQueries[i][1]+1]--;
		}
		partial_sum(begin(diff),end(diff),begin(diff));

		for(int i = 0; i < m ; ++i){
			if(diff[i] < solNums[i])
				return false;
		}
		return true;
	}
public:
	int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
		solNums = nums;
		solQueries = queries;
		Maxcount = 0;

		if (!canZeroArray(queries))
			return -1;

		vector<vector<int>> empty;
		dfs(empty, 0);

		return Maxcount;;
	}
};
#else
class Solution {
private:
    vector<int> solNums;
    vector<vector<int>> solQueries;

    bool canZeroArray(const vector<bool>& used) {
        int n = solNums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < used.size(); ++i) {
            if (used[i]) {
                int l = solQueries[i][0], r = solQueries[i][1];
                diff[l]++;
                if (r + 1 < n) diff[r + 1]--;
            }
        }

        for (int i = 1; i < n; ++i)
            diff[i] += diff[i - 1];

        for (int i = 0; i < n; ++i)
            if (diff[i] < solNums[i])
                return false;

        return true;
    }

public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        solNums = nums;
        solQueries = queries;
        int n = nums.size(), m = queries.size();

        vector<bool> used(m, true);
        if (!canZeroArray(used))
            return -1;

        // 각 쿼리가 커버하는 길이로 min heap 구성
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            pq.emplace(r - l + 1, i);
        }

        while (!pq.empty()) {
            auto [_, idx] = pq.top(); pq.pop();
            used[idx] = false;

            if (!canZeroArray(used)) {
                used[idx] = true;  // 복원
            }
        }

        int removed = count(used.begin(), used.end(), false);
        return removed;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> nums;
	vector<vector<int>> queries;
	int ans, res;

	nums = {1,0},queries = {{1,1},{1,1},{0,1},{0,1},{0,0},{1,1}};
	ans = 5;
	res = sol.maxRemoval(nums,queries);
	println("ans : {} , res : {}",ans,res);

	nums = {2,0,2}, queries = {{0,2},{0,2},{1,1}};
	ans = 1;
	res = sol.maxRemoval(nums,queries);
	println("ans : {} , res : {}",ans,res);

	nums = {1,1,1,1}, queries = {{1,3},{0,2},{1,3},{1,2}};
	ans = 2;
	res = sol.maxRemoval(nums,queries);
	println("ans : {} , res : {}",ans,res);

	nums = {1,2,3,4}, queries = {{0,3}};
	ans = -1;
	res = sol.maxRemoval(nums,queries);
	println("ans : {} , res : {}",ans,res);

	return 0;
}
