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
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> diff;  // 차분 정보만 저장
        for (auto& m : meetings) {
            diff[m[0] - 1]++;
            diff[m[1]]--;
        }
        int res = 0;
        int curr = 0;
        int prev = 0;
        for (auto& [day, delta] : diff) {
            if (curr == 0 && day > prev) {
                res += day - prev;  // 비어있는 구간 계산
            }
            curr += delta;
            prev = day;
        }
        if (curr == 0 && prev < days) {
            res += days - prev;
        }
        return res;
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
