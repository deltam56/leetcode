/**
* You are given an n x n square matrix of integers grid. Return the matrix such that:
* 
* The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
* The diagonals in the top-right triangle are sorted in non-decreasing order.
*  
* 
* Example 1:
* 
* Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
* 
* Output: [[8,2,3],[9,6,7],[4,5,1]]
* 
* Explanation:
* 
* 
* 
* The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
* 
* [1, 8, 6] becomes [8, 6, 1].
* [9, 5] and [4] remain unchanged.
* The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
* 
* [7, 2] becomes [2, 7].
* [3] remains unchanged.
* Example 2:
* 
* Input: grid = [[0,1],[1,2]]
* 
* Output: [[2,1],[1,0]]
* 
* Explanation:
* 
* 
* 
* The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.
* 
* Example 3:
* 
* Input: grid = [[1]]
* 
* Output: [[1]]
* 
* Explanation:
* 
* Diagonals with exactly one element are already in order, so no changes are needed.
* 
*  
* 
* Constraints:
* 
* grid.length == grid[i].length == n
* 1 <= n <= 10
* -105 <= grid[i][j] <= 105
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>

using namespace std;
#if 0
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n <= 1) return grid;

		//mid, lower side
        for (int d = 0; d <= n - 1; ++d) {
            vector<pair<int,int>> coord;
            vector<int> vals;
            for (int k = 0; d + k < n && k < n; ++k) {
                int i = d + k, j = k;
                coord.emplace_back(i, j);
                vals.push_back(grid[i][j]);
            }
            sort(vals.begin(), vals.end(), greater<int>()); // decreasing order
            for (int t = 0; t < (int)coord.size(); ++t) {
                auto [i, j] = coord[t];
                grid[i][j] = vals[t];
            }
        }
		//upper side
        for (int d = 1; d <= n - 1; ++d) {
            vector<pair<int,int>> coord;
            vector<int> vals;
            for (int k = 0; k < n && d + k < n; ++k) {
                int i = k, j = d + k;
                coord.emplace_back(i, j);
                vals.push_back(grid[i][j]);
            }
            sort(vals.begin(), vals.end()); // incresing order
            for (int t = 0; t < (int)coord.size(); ++t) {
                auto [i, j] = coord[t];
                grid[i][j] = vals[t];
            }
        }

        return grid;
    }
};
#else
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n <= 1) return grid;

        // d = i - j  (같은 d는 같은 ↘ 대각선)
        // d >= 0 → 하삼각(메인 포함): 내림차순
        // d <  0 → 상삼각           : 오름차순
        for (int d = -(n - 1); d <= (n - 1); ++d) {
            // 시작점: d>=0이면 (d,0), d<0이면 (0,-d)
            int i = d >= 0 ? d : 0;
            int j = d >= 0 ? 0 : -d;

            vector<pair<int,int>> coord;
            vector<int> vals;
            for (; i < n && j < n; ++i, ++j) {
                coord.emplace_back(i, j);
                vals.push_back(grid[i][j]);
            }

            if (d >= 0) {
                sort(vals.begin(), vals.end(), greater<int>()); // 하삼각: 내림차순
            } else {
                sort(vals.begin(), vals.end());                 // 상삼각: 오름차순
            }

            for (int t = 0; t < (int)coord.size(); ++t) {
                auto [ri, cj] = coord[t];
                grid[ri][cj] = vals[t];
            }
        }
        return grid;
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> grid;
	vector<vector<int>> ans,res;

	grid = {{1,7,3},{9,8,2},{4,5,6}};
	ans = {{8,2,3},{9,6,7},{4,5,1}};
	res = sol.sortMatrix(grid);
	println("ans : {} , res : {}",ans,res);

	grid = {{0,1},{1,2}};
	ans = {{2,1},{1,0}};
	res = sol.sortMatrix(grid);
	println("ans : {} , res : {}",ans,res);

	grid = {{1}};
	ans = {{1}};
	res = sol.sortMatrix(grid);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
