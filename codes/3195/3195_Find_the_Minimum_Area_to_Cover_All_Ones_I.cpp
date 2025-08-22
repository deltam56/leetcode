/**
 * 3195. Find the Minimum Area to Cover All Ones I
 * You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
 * 
 * Return the minimum possible area of the rectangle.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: grid = [[0,1,0],[1,0,1]]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * 
 * 
 * The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
 * 
 * Example 2:
 * 
 * Input: grid = [[1,0],[0,0]]
 * 
 * Output: 1
 * 
 * Explanation:
 * 
 * 
 * 
 * The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
 * 
 *  
 * 
 * Constraints:
 * 
 * 1 <= grid.length, grid[i].length <= 1000
 * grid[i][j] is either 0 or 1.
 * The input is generated such that there is at least one 1 in grid.
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
	int minimumArea(vector<vector<int>>& grid) {
		int l = INT_MAX, r = INT_MIN;
		int t = INT_MAX, b = INT_MIN;
		int m = grid.size();
		int n = grid[0].size();

		for(int i = 0 ; i < m; ++i){
			for(int j = 0 ; j < n ; ++j){
				if(grid[i][j] == 1){
					l = min(l,j);
					r = max(r,j);
					t = min(t,i);
					b = max(b,i);
				}
			}
		}
		return (r-l+1)*(b-t+1);
	}
};

int main() {
	Solution sol;
	vector<vector<int>> grid;
	int ans,res;

	grid = {{0,1,0},{1,0,1}};
	ans = 6;
	res = sol.minimumArea(grid);
	println("ans : {}, res : {}", ans,res);

	grid = {{1,0},{0,0}};
	ans = 1;
	res = sol.minimumArea(grid);
	println("ans : {}, res : {}", ans,res);

	return 0;
}
