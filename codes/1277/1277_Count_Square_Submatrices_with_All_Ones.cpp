/**
* 1277. Count Square Submatrices with All Ones
* Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
* 
*  
* 
* Example 1:
* 
* Input: matrix =
* [
*   [0,1,1,1],
*   [1,1,1,1],
*   [0,1,1,1]
* ]
* Output: 15
* Explanation: 
* There are 10 squares of side 1.
* There are 4 squares of side 2.
* There is  1 square of side 3.
* Total number of squares = 10 + 4 + 1 = 15.
* Example 2:
* 
* Input: matrix = 
* [
*   [1,0,1],
*   [1,1,0],
*   [1,1,0]
* ]
* Output: 7
* Explanation: 
* There are 6 squares of side 1.  
* There is 1 square of side 2. 
* Total number of squares = 6 + 1 = 7.
*  
* 
* Constraints:
* 
* 1 <= arr.length <= 300
* 1 <= arr[0].length <= 300
* 0 <= arr[i][j] <= 1
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
#if 1
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        if (m == 0) return 0;
        int n = (int)matrix[0].size();

        // dp[i][j]: (i,j)를 오른쪽-아래 꼭짓점으로 하는 all-ones 정사각형 최대 변 길이
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int total = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    total += dp[i][j];
                }
            }
        }
        return total;
    }
};
#else
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
		//max_square_size = matrix.size()
		//for i < max_square_size  <- max square 만큼 하나씩 증가하며 사이즈 탐색..
		// 2중 반복,,?
		//
		// 아니면
		// 가장큰 사이즈 하나 구하고, 0 으로 바꾸고, 다음 큰 사이즈 탐색하고, 0으로 바꾸고

		int max_square_size = matrix.size();
		int total_count = 0;
		for(int i = 0 ; i < max_square_size; ++i){
			vecor<int> cmp_mat(i,1);
			//j => 열 보며 원소가 1111... 연속된걸 셈
			//k => 행 보며 1111 이 연속된걸 셈
			int row_count = 0;
			for(int k = 0 ; k < matrix.size()-i ; ++k){
				for(int j = 0; j < matrix[0].size()-i ; ++j){
					if({matrix[k].begin()+j,matrix[k].begin()+j+i} == cmp_mat){
						int l = k+1;
						while(l < matrix.size()-i){
							if({matrix[l].begin()+j,matrix[k].begin+j+i} != cmp_mat){
								break;
							}
							row_count++;
							if(row_count == i){
								total_count++;
							}
						}
					}
				}
			}
		}

		return total_count;

//		for(int i = max_square_size; i > 0; --i){
//			vector<int> cmp_mat(i,1);
//			for(int k=0; k < matrix.size()-i; ++k){
//				for(int j = 0; j < matrix[j].size()-i; ++j){
//					vector<int> submat = {matrix.begin()+j, matrix.end()-i};
//					if(submat == cmp_mat){
//
//
//					}
//				}
//			}
//		}
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> matrix;
	int ans,res;

	matrix ={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
	ans = 15;
	res = sol.countSquares(matrix);
	println("ans : {}, res : {}",ans,res);

	matrix = {{1,0,1},{1,1,0},{1,1,0}};
	ans = 7;
	res = sol.countSquares(matrix);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
