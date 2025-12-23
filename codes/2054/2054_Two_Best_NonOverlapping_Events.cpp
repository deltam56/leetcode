/**
 * 2054. Two Best Non-Overlapping Events
 * You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
 * 
 * Return this maximum sum.
 * 
 * Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: events = [[1,3,2],[4,5,2],[2,4,3]]
 * Output: 4
 * Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
 * Example 2:
 * 
 * Example 1 Diagram
 * Input: events = [[1,3,2],[4,5,2],[1,5,5]]
 * Output: 5
 * Explanation: Choose event 2 for a sum of 5.
 * Example 3:
 * 
 * 
 * Input: events = [[1,5,3],[1,5,1],[6,6,5]]
 * Output: 8
 * Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 * 
 * 
 * Constraints:
 * 
 * 2 <= events.length <= 10^5
 * events[i].length == 3
 * 1 <= startTimei <= endTimei <= 10^9
 * 1 <= valuei <= 10^6
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
	int maxTwoEvents(vector<vector<int>>& events) {
		int n = events.size();
		sort(events.begin(), events.end());

		vector<int> suffixMax(n + 1, 0);
		for (int i = n - 1; i >= 0; i--) {
			suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
		}

		int result = 0;

		for (auto& event : events) {
			int end = event[1];
			int value = event[2];

			result = max(result, value);

			int lo = 0, hi = n;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				if (events[mid][0] > end) {
					hi = mid;
				} else {
					lo = mid + 1;
				}
			}

			result = max(result, value + suffixMax[lo]);
		}

		return result;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> events;
	int ans,res;

	events = {{1,3,2},{4,5,2},{2,4,3}};
	ans = 4;
	res = sol.maxTwoEvents(events);
	println("ans : {}, res : {}",ans,res);

	events = {{1,3,2},{4,5,2},{1,5,5}};
	ans = 5;
	res = sol.maxTwoEvents(events);
	println("ans : {}, res : {}",ans,res);

	events = {{1,5,3},{1,5,1},{6,6,5}};
	ans = 8;
	res = sol.maxTwoEvents(events);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
