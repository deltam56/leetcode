/**
 * 120. Triangle
 * Given a triangle array, return the minimum path sum from top to bottom.
 * 
 * For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * Example 2:
 * 
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * 
 * Constraints:
 * 
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 * 
 * 
 * Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
using namespace std;

/*
   class Solution {
   private:
   int dfs(vector<vector<int>>& triangle,int d, int i, int sum){
   if(d >= triangle.size())return sum;
   sum += triangle[d][i];
   return min(dfs(triangle,d+1,i,sum),dfs(triangle,d+1,i+1,sum));
   }
   public:
   int minimumTotal(vector<vector<int>>& triangle) {
   return dfs(triangle, 0,0,0);
   }
   };
   */

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int R = (int)triangle.size();
		for (int i = R - 2; i >= 0; --i) {          // 위로 올라가며 갱신
			for (int j = 0; j <= i; ++j) {          // j는 0..i
				triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
	}
};
int main() {
	Solution sol;
	vector<vector<int>> triangle;
	int ans,res;

	triangle = {{-1},{-2,-3}};
	ans = -4;
	res = sol.minimumTotal(triangle);
	println("ans : {} , res : {}",ans,res);


	triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
	ans = 11;
	res = sol.minimumTotal(triangle);
	println("ans : {} , res : {}",ans,res);


	triangle = {{-10}};
	ans = -10;
	res = sol.minimumTotal(triangle);
	println("ans : {} , res : {}",ans,res);

	return 0;
}
