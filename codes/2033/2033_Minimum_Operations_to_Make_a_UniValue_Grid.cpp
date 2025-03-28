/**
* 2033. Minimum Operations to Make a Uni-Value Grid
* You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
* 
* A uni-value grid is a grid where all the elements of it are equal.
* 
* Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
* 
* 
* 
* Example 1:
* 
* 
* Input: grid = [[2,4],[6,8]], x = 2
* Output: 4
* Explanation: We can make every element equal to 4 by doing the following:
* - Add x to 2 once.
* - Subtract x from 6 once.
* - Subtract x from 8 twice.
* A total of 4 operations were used.
* Example 2:
* 
* 
* Input: grid = [[1,5],[2,3]], x = 1
* Output: 5
* Explanation: We can make every element equal to 3.
* Example 3:
* 
* 
* Input: grid = [[1,2],[3,4]], x = 2
* Output: -1
* Explanation: It is impossible to make every element equal.
* 
* 
* Constraints:
* 
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 105
* 1 <= m * n <= 105
* 1 <= x, grid[i][j] <= 104
**/

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
		vector<int> temp;

		for (const vector<int>& rows : grid)
			for (const int& elem : rows)
				temp.push_back(elem);

		sort(begin(temp), end(temp));

		for (int i = 1; i < temp.size(); ++i)
			if (abs(temp[i] - temp[i - 1]) % x)
				return -1;

		int median = temp[temp.size() / 2];
		int cnt = 0;

		for (const int& elem : temp)
			cnt += abs(elem - median) / x;

		return cnt;
    }
};
int main() {
	Solution sol;
	vector<vector<int>> grid;
	int x;
	int ans,res;

	grid = {{2,4},{6,8}};
	x = 2;
	ans = 4;
	res = sol.minOperations(grid,x);
	println("ans : {} , res : {}",ans,res);


	grid = {{1,5},{2,3}};
	x = 1;
	ans = 5;
	res = sol.minOperations(grid,x);
	println("ans : {} , res : {}",ans,res);

	grid = {{1,2},{3,4}};
	x = 2;
	ans = -1;
	res = sol.minOperations(grid,x);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
