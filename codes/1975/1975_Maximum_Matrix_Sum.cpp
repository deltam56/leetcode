/**
 * 1975. Maximum Matrix Sum
 * You are given an n x n integer matrix. You can do the following operation any number of times:
 * 
 * Choose any two adjacent elements of matrix and multiply each of them by -1.
 * Two elements are considered adjacent if and only if they share a border.
 * 
 * Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,-1],[-1,1]]
 * Output: 4
 * Explanation: We can follow the following steps to reach sum equals 4:
 * - Multiply the 2 elements in the first row by -1.
 * - Multiply the 2 elements in the first column by -1.
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
 * Output: 16
 * Explanation: We can follow the following step to reach sum equals 16:
 * - Multiply the 2 last elements in the second row by -1.
 * 
 * 
 * Constraints:
 * 
 * n == matrix.length == matrix[i].length
 * 2 <= n <= 250
 * -10^5 <= matrix[i][j] <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int absMin = INT_MAX;
        int negCnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = matrix[i][j];
                if (val < 0) negCnt++;
                sum += abs(val);
                absMin = min(absMin, abs(val));
            }
        }
        if (negCnt % 2 == 1) {
            sum -= 2LL * absMin;
        }
        return sum;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> matrix;
	long long ans,res;

	matrix = {{1,-1},{-1,1}};
	ans = 4;
	res = sol.maxMatrixSum(matrix);
	println("ans : {}, res : {}",ans,res);

	matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
	ans = 16;
	res = sol.maxMatrixSum(matrix);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
