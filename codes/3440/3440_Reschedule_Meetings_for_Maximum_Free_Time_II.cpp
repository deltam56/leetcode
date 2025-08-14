/**
 * 3440. Reschedule Meetings for Maximum Free Time II
 * You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.
 * 
 * These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].
 * 
 * You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.
 * 
 * Return the maximum amount of free time possible after rearranging the meetings.
 * 
 * Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.
 * 
 * Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: eventTime = 5, startTime = [1,3], endTime = [2,5]
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * 
 * 
 * Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].
 * 
 * Example 2:
 * 
 * Input: eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]
 * 
 * Output: 7
 * 
 * Explanation:
 * 
 * 
 * 
 * Reschedule the meeting at [0, 1] to [8, 9], leaving no meetings during the time [0, 7].
 * 
 * Example 3:
 * 
 * Input: eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * 
 * 
 * Reschedule the meeting at [3, 4] to [8, 9], leaving no meetings during the time [1, 7].
 * 
 * Example 4:
 * 
 * Input: eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * There is no time during the event not occupied by meetings.
 * 
 * 
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
using namespace std; //편의성위해..
					 // class Solution {
					 // public:
					 //     int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
					 // 		int tmp_max_gap = startTime[1];
					 // 		int max_gap=0;
					 // 
					 // 		for(int i = 1 ; i < startTime.size()-1; ++i){
					 // 			if(tmp_max_gap < startTime[i+1] - endTime[i-1]){
					 // 				tmp_max_gap = startTime[i+1] - endTime[i-1];
					 // 				max_gap = tmp_max_gap - (endTime[i]-startTime[i]);
					 // 			}
					 // 		}
					 // 
					 // 		max_gap = max(max_gap, (eventTime - endTime[endTime.size()-2]-(endTime.back()-startTime.back())));
					 // 		return max_gap;
					 //     }
					 // };


class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; ++i)
            meetings[i] = {startTime[i], endTime[i]};

        auto getMaxGap = [&](const vector<pair<int, int>>& M) {
            int prevEnd = 0;
            int maxGap = 0;
            for (auto [s, e] : M) {
                maxGap = max(maxGap, s - prevEnd);
                prevEnd = e;
            }
            maxGap = max(maxGap, eventTime - prevEnd);
            return maxGap;
        };
        int answer = getMaxGap(meetings);
        for (int i = 0; i < n; ++i) {
            int dur = meetings[i].second - meetings[i].first;

            vector<pair<int, int>> rest;
            for (int j = 0; j < n; ++j)
                if (i != j)
                    rest.push_back(meetings[j]);

            vector<pair<int, int>> gaps;
            int prevEnd = 0;
            for (auto [s, e] : rest) {
                if (s > prevEnd)
                    gaps.emplace_back(prevEnd, s);
                prevEnd = e;
            }
            if (prevEnd < eventTime)
                gaps.emplace_back(prevEnd, eventTime);

            for (auto [gs, ge] : gaps) {
                if (ge - gs >= dur) {
                    vector<pair<int, int>> newMeetings = rest;
                    newMeetings.emplace_back(gs, gs + dur);
                    sort(newMeetings.begin(), newMeetings.end());
                    int g = getMaxGap(newMeetings);
                    answer = max(answer, g);
                }
            }
        }

        return answer;
    }
};

int main() {
	Solution sol;
	int eventTime;
	vector<int> startTime, endTime;
	int ans,res;

	eventTime = 5;
	startTime = {1,3};
	endTime = {2,5};
	ans = 2;
	res = sol.maxFreeTime(eventTime,startTime,endTime);
	println("ans : {}, res :{}",ans,res);


	eventTime = 10;
	startTime = {0,7,9};
	endTime = {1,8,10};
	ans = 7;
	res = sol.maxFreeTime(eventTime,startTime,endTime);
	println("ans : {}, res :{}",ans,res);

	eventTime = 10;
	startTime = {0,3,7,9};
	endTime = {1,4,8,10};
	ans = 6;
	res = sol.maxFreeTime(eventTime,startTime,endTime);
	println("ans : {}, res :{}",ans,res);

	eventTime = 5;
	startTime = {0,1,2,3,4};
	endTime = {1,2,3,4,5};
	ans = 0;
	res = sol.maxFreeTime(eventTime,startTime,endTime);
	println("ans : {}, res :{}",ans,res);

	return 0;
}
