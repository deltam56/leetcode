/**
* 73. Set Matrix Zeroes
* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
* 
* You must do it in place.
* 
* 
* 
* Example 1:
* 
* 
* Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
* Output: [[1,0,1],[0,0,0],[1,0,1]]
* Example 2:
* 
* 
* Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
* Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
* 
* 
* Constraints:
* 
* m == matrix.length
* n == matrix[0].length
* 1 <= m, n <= 200
* -231 <= matrix[i][j] <= 231 - 1
* 
* 
* Follow up:
* 
* A straightforward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <bitset>

using namespace std; //편의성위해..
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		bitset<200> col_bs;
		bitset<200> row_bs;

		for(int i = 0 ; i < matrix.size(); ++i){
			for(int j = 0 ; j < matrix[0].size(); ++j){
				if(matrix[i][j] == 0){
					col_bs.set(i);
					row_bs.set(j);
				}
			}
		}

		for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0 ; j < matrix[0].size();++j){
				if (col_bs[i] == 1 || row_bs[j] == 1) matrix[i][j] = 0;;
			}
		}

    }
};
void matprint(const vector<vector<int>> matrix, const vector<vector<int>> ans){
	println("matrix: ");
	for(int i = 0; i < matrix.size() ; ++i)
		println("{}",matrix[i]);
	println("ans: ");
	for(int i = 0; i < matrix.size() ; ++i)
		println("{}",ans[i]);
}
int main() {
	Solution sol;
	vector<vector<int>> matrix;
	vector<vector<int>> ans;

	matrix = {{1,1,1},{1,0,1},{1,1,1}};
	ans = {{1,0,1},{0,0,0},{1,0,1}};
	sol.setZeroes(matrix);
	matprint(matrix, ans);

	matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	ans = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
	sol.setZeroes(matrix);
	matprint(matrix, ans);

    return 0;
}
