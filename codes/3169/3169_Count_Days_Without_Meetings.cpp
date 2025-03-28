/**
* 3169. Count Days Without Meetings
* You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
* 
* Return the count of days when the employee is available for work but no meetings are scheduled.
* 
* Note: The meetings may overlap.
* 
*  
* 
* Example 1:
* 
* Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
* 
* Output: 2
* 
* Explanation:
* 
* There is no meeting scheduled on the 4th and 8th days.
* 
* Example 2:
* 
* Input: days = 5, meetings = [[2,4],[1,3]]
* 
* Output: 1
* 
* Explanation:
* 
* There is no meeting scheduled on the 5th day.
* 
* Example 3:
* 
* Input: days = 6, meetings = [[1,6]]
* 
* Output: 0
* 
* Explanation:
* 
* Meetings are scheduled for all working days.
* 
*  
* 
* Constraints:
* 
* 1 <= days <= 109
* 1 <= meetings.length <= 105
* meetings[i].length == 2
* 1 <= meetings[i][0] <= meetings[i][1] <= days
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
#include <map>
using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res =0;
		vector<int> calendar(days+1,0);
		for(auto& m : meetings){
			calendar[m[0]-1] ++;
			calendar[m[1]] --;
		}
		partial_sum(calendar.begin(),calendar.end(),calendar.begin());
		for(int i=0 ; i< calendar.size()-1 ; i++)
			if(calendar[i] == 0)
				res ++;
		return res;
    }
};
#else
#include <algorithm>

class Solution {
private:
	vector<pair<int, int>> mergeIntervals(vector<vector<int>>& meetings) {
		vector<pair<int, int>> intervals;

		sort(begin(meetings), end(meetings));
		intervals.push_back({meetings[0][0], meetings[0][1]});

		for (int i = 1; i < meetings.size(); ++i) {
			if (intervals.back().second + 1 >= meetings[i][0]) // Overlapped
				intervals.back().second = max(intervals.back().second,
						meetings[i][1]);
			else // Non-overlapped
				 intervals.push_back({meetings[i][0], meetings[i][1]});
		}

		return intervals;
	}

public:
    int countDays(int days, vector<vector<int>>& meetings) {
		vector<pair<int, int>> intervals = mergeIntervals(meetings);
		int cnt = 0;

		for (const auto& [s, e] : intervals)
			cnt += e - s + 1;

		return days - cnt;
    }
};
#endif
int main() {
	Solution sol;
	int days;
	vector<vector<int>> meetings;
	int ans,res;

	days = 10;
	meetings = {{5,7},{1,3},{9,10}};
	ans = 2;
	res = sol.countDays(days, meetings);
	println("ans : {}, res: {}",ans,res);

	days = 5;
	meetings = {{2,4},{1,3}};
	ans = 1;
	res = sol.countDays(days, meetings);
	println("ans : {}, res: {}",ans,res);

	days = 6;
	meetings = {{1,6}};
	ans = 0;
	res = sol.countDays(days, meetings);
	println("ans : {}, res: {}",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
