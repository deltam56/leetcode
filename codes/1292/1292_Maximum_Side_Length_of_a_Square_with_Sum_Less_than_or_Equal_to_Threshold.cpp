/**
 * 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 * Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
 * 
 * Example 1:
 * 
 * Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
 * Output: 2
 * Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
 * Example 2:
 * 
 * Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
 * Output: 0
 * 
 * Constraints:
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 300
 * 0 <= mat[i][j] <= 10^4
 * 0 <= threshold <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
using namespace std;
#if 0
class Solution {
public:
	int maxSideLength(vector<vector<int>>& mat, int threshold) {
		int stride = 1;
		int cnt = 0;
		int m = mat[0].size();
		int n = mat.size();
		int minside = 1;
		int maxside = min(m,n);
		int side = (minside+maxside)/2;

		for(int j = 0; j < n; j+= stride){
			for(int i = 0; i < m ; i+= stride){
				int sum = 0;
					for(int k= j; k < j+side; ++k){
						sum += accumulate(&mat[k][i],&mat[k][i+side],0);
					}
					if(sum > threshold) side = (minside+side)/2;
					if(sum < threshold) side = (maxside+side)/2;
					if(sum == threshold) return side;
			}
		}
		return 0;
	}
};
#endif
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        // 1. 각 행에 대해 partial_sum 적용
        for (int i = 0; i < m; ++i) {
            partial_sum(mat[i].begin(), mat[i].end(), prefix[i + 1].begin() + 1);
        }
        // 2. 각 열에 대해 누적 (위에서 아래로)
        for (int j = 1; j <= n; ++j) {
            for (int i = 2; i <= m; ++i) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
        // O(1) 영역 합 계산
        auto getSum = [&](int r1, int c1, int r2, int c2) {
            return prefix[r2+1][c2+1] - prefix[r1][c2+1] 
                 - prefix[r2+1][c1] + prefix[r1][c1];
        };
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int side = result + 1; i + side <= m && j + side <= n; ++side) {
                    if (getSum(i, j, i + side - 1, j + side - 1) <= threshold) {
                        result = side;
                    } else {
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> mat;
	int threshold;
	int ans,res;

	mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}}, threshold = 4;
	ans = 2;
	res = sol.maxSideLength(mat,threshold);
	println("ans : {}, res : {}",ans,res);

	mat = {{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}}, threshold = 1;
	ans = 0;
	res = sol.maxSideLength(mat,threshold);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
