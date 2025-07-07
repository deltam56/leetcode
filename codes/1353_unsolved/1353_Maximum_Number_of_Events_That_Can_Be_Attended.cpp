/**
 * 1353. Maximum Number of Events That Can Be Attended
 * You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
 * 
 * You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * Example 2:
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 *  
 * 
 * Constraints:
 * 
 * 1 <= events.length <= 10^5
 * events[i].length == 2
 * 1 <= startDayi <= endDayi <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <queue>
using namespace std; //편의성위해..

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 0, i = 0, res = 0;
        int n = events.size();

        // 최대 종료일까지만 루프를 돕니다
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty())
                day = events[i][0]; // 현재 heap이 비었으면, 다음 이벤트의 시작일부터 시작

            // 시작일이 현재 날짜 이하인 모든 이벤트의 종료일을 heap에 추가
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                ++i;
            }

            // 이미 종료된 이벤트는 heap에서 제거
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();

            if (!minHeap.empty()) {
                minHeap.pop(); // 오늘 하나 참석
                ++res;
            }

            ++day; // 다음 날로 이동
        }

        return res;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> events;
	int ans,res;

	events = {{1,2},{2,3},{3,4}};
	ans = 3;
	res = sol.maxEvents(events);
	println("ans : {} , res :{} ",ans,res);
	events= {{1,2},{2,3},{3,4},{1,2}};
		ans = 4;
	res = sol.maxEvents(events);
	println("ans : {} , res :{} ",ans,res);

	return 0;
}
