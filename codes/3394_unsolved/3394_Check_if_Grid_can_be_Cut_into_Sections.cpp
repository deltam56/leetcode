/**
* 3394. Check if Grid can be Cut into Sections
* You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
* 
* (startx, starty): The bottom-left corner of the rectangle.
* (endx, endy): The top-right corner of the rectangle.
* Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
* 
* Each of the three resulting sections formed by the cuts contains at least one rectangle.
* Every rectangle belongs to exactly one section.
* Return true if such cuts can be made; otherwise, return false.
* 
*  
* 
* Example 1:
* 
* Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
* 
* Output: true
* 
* Explanation:
* 
* 
* 
* The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.
* 
* Example 2:
* 
* Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
* 
* Output: true
* 
* Explanation:
* 
* 
* 
* We can make vertical cuts at x = 2 and x = 3. Hence, output is true.
* 
* Example 3:
* 
* Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
* 
* Output: false
* 
* Explanation:
* 
* We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.
* 
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std; //편의성위해..
class Solution {
#if 0
	bool mergeIntervals(vector<vector<int>>& intervals) {
		vector<pair<int, int>> temp;

		sort(begin(intervals),end(intervals));
		temp.push_back({intervals[0][0], intervals[0][1]});

		for(int i = 1 ; i < intervals.size() ; i++)
			if (temp.back().second > intervals[i][0]) // Overlapped
				temp.back().second = max(temp.back().second, intervals[i][1]);
			 else // Non-overlapped
				temp.push_back({intervals[i][0], intervals[i][1]});

		return temp.size() >= 3;
	}
#else
	bool mergeIntervals(vector<vector<int>>& intervals) {
		sort(begin(intervals),end(intervals));
		int prev = intervals[0][1];
		int cnt = 0;

		for(int i = 1 ; i < intervals.size() ; i++) {
			if (prev <= intervals[i][0])
				cnt++;
			prev = max(prev, intervals[i][1]);
		}

		return cnt >= 2;
	}
#endif

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
		vector<vector<int>> horizon,vertical;

		for(vector<int> r : rectangles){
			horizon.push_back({r[0],r[2]});
			vertical.push_back({r[1],r[3]});
		}

		return mergeIntervals(horizon) || mergeIntervals(vertical);
    }
};

int main() {
	Solution sol;
	int n;
	vector<vector<int>> rectangles;
	bool ans,res;

	n = 5;
	rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
	ans = true;
	res = sol.checkValidCuts(n,rectangles);
	println("ans : {} , res : {}",ans,res);

	n = 4;
	rectangles = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};
	ans = true;
	res = sol.checkValidCuts(n,rectangles);
	println("ans : {} , res : {}",ans,res);

	n = 4;
	rectangles = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};
	ans = false;
	res = sol.checkValidCuts(n,rectangles);
	println("ans : {} , res : {}",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
