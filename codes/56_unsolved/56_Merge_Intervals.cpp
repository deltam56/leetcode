/**
* 56. Merge Intervals
* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
* 
*  
* 
* Example 1:
* 
* Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
* Output: [[1,6],[8,10],[15,18]]
* Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
* Example 2:
* 
* Input: intervals = [[1,4],[4,5]]
* Output: [[1,5]]
* Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*  
* 
* Constraints:
* 
* 1 <= intervals.length <= 10^4
* intervals[i].length == 2
* 0 <= starti <= endi <= 10^4
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
using namespace std; //편의성위해..
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res(1,{0,0});
        sort(intervals.begin(),intervals.end());
		res[0] = intervals[0];

		for(int i = 1; i < intervals.size(); i++){
			if(res.back()[1] >= intervals[i][0])
				res.back()[1] = max(res.back()[1],intervals[i][1]);
			else
				res.push_back(intervals[i]);

        }
		return res;
    }
};
int main() {
	Solution sol;
	vector<vector<int>> intervals,ans,res;

	intervals = {{1,3},{2,6},{8,10},{15,18}};
	ans = {{1,6},{8,10},{15,18}};
	res = sol.merge(intervals);
	println("ans : {} , res : {}", ans,res);

	intervals = {{1,4},{4,5}};
	ans = {{1,5}};
	res = sol.merge(intervals);
	println("ans : {} , res : {}", ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
