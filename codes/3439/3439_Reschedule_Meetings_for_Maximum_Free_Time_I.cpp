/**
 * 3439. Reschedule Meetings for Maximum Free Time I
 * You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
 * 
 * You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
 * 
 * You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
 * 
 * The relative order of all the meetings should stay the same and they should remain non-overlapping.
 * 
 * Return the maximum amount of free time possible after rearranging the meetings.
 * 
 * Note that the meetings can not be rescheduled to a time outside the event.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
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
 * Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * 
 * 
 * Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].
 * 
 * Example 3:
 * 
 * Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
 * 
 * Output: 0
 * 
 * Explanation:
 * 
 * There is no time during the event not occupied by meetings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= eventTime <= 109
 * n == startTime.length == endTime.length
 * 2 <= n <= 105
 * 1 <= k <= n
 * 0 <= startTime[i] < endTime[i] <= eventTime
 * endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <queue>

using namespace std; //편의성위해..
#if 0
class Solution {
private:
	int maxgap(vector<int>& startTime, vector<int>& endTime,int eventTime){
		int max_gap = 0;
		for(int i = 1; i < startTime.size(); ++i){
			max_gap = max(max_gap, startTime[i]-endTime[i-1]);
		}
		return max(max_gap, eventTime-endTime.back());
	}
public:
	int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
		//              <gap, starttime,duration>
		priority_queue<tuple<int,int,int>> prio_gap;
		vector<int> mv_starttime,mv_endtime;
		int max_gap = 0;

		//초기값
		if(startTime[0] != 0)
			prio_gap.push({startTime[0],startTime[0],endTime[0]-startTime[0]});

		for(int i = 1 ; i < startTime.size(); ++i){
			prio_gap.push({startTime[i]-endTime[i-1],startTime[i],endTime[i]-startTime[i]});
		}

		int count = 0;
		while(prio_gap != empty && count < k){
			mv_starttime.pushback()
				count ++;
		}

		return max_gap;
	}
};
///////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
	vector<int> duration(n);
        for (int i = 0; i < n; ++i) {
            duration[i] = endTime[i] - startTime[i];
        }

        vector<int> newStart(n), newEnd(n);
        int moved = 0;
        newStart[0] = 0;
        newEnd[0] = duration[0];
        if (startTime[0] != 0) moved++;

        for (int i = 1; i < n; ++i) {
            int shiftedStart = newEnd[i - 1];
            int shiftedEnd = shiftedStart + duration[i];

            if (startTime[i] != shiftedStart) moved++;
            if (moved > k) {
                for (int j = i; j < n; ++j) {
                    newStart[j] = startTime[j];
                    newEnd[j] = endTime[j];
                }
                break;
            }

            newStart[i] = shiftedStart;
            newEnd[i] = shiftedEnd;
        }

        int maxGap = 0;
        maxGap = max(maxGap, newStart[0] - 0);
        for (int i = 1; i < n; ++i) {
            maxGap = max(maxGap, newStart[i] - newEnd[i - 1]);
        }
        maxGap = max(maxGap, eventTime - newEnd.back());

        return maxGap;
    }
};
#else
class Solution {
public:
    static int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int n=startTime.size();
        int busy=0;
        for (int i=0; i < k; i++)
            busy+=endTime[i]-startTime[i];

        if (n==k) return eventTime-busy;

        int ans=startTime[k]-busy;

        for (int l=0, r=k; r<n; l++, r++) {
            busy+=(endTime[r]-startTime[r])-(endTime[l]-startTime[l]);
            int end=(r==n-1)?eventTime:startTime[r+1];
            int start=endTime[l];
            ans=max(ans, end-start-busy);
        }
        return ans;
    }
};
#endif
int main() {
	Solution sol;
	int eventTime, k;
	vector<int> startTime, endTime;
	int ans,res;

	eventTime = 5;
	k = 1;
	startTime = {1,3};
	endTime = {2,5};
	ans = 2;
	res = sol.maxFreeTime(eventTime, k, startTime, endTime);
	println("ans : {}, res :{}",ans,res);

	eventTime = 10;
	k = 1;
	startTime = {0,2,9};
	endTime = {1,4,10};
	ans = 6;
	res = sol.maxFreeTime(eventTime, k, startTime, endTime);
	println("ans : {}, res :{}",ans,res);

	eventTime = 5;
	k = 2;
	startTime = {0,1,2,3,4};
	endTime = {1,2,3,4,5};
	ans = 0;
	res = sol.maxFreeTime(eventTime, k, startTime, endTime);
	println("ans : {}, res :{}",ans,res);

	return 0;
}
