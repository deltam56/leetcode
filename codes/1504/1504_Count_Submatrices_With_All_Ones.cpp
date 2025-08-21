/**
* 1504. Count Submatrices With All Ones
* Given an m x n binary matrix mat, return the number of submatrices that have all ones.
* 
* Example 1:
* 
* 
* Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
* Output: 13
* Explanation:
* There are 6 rectangles of side 1x1.
* There are 2 rectangles of side 1x2.
* There are 3 rectangles of side 2x1.
* There is 1 rectangle of side 2x2.
* There is 1 rectangle of side 3x1.
* Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
* Example 2:
* 
* 
* Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
* Output: 24
* Explanation:
* There are 8 rectangles of side 1x1.
* There are 5 rectangles of side 1x2.
* There are 2 rectangles of side 1x3.
* There are 4 rectangles of side 2x1.
* There are 2 rectangles of side 2x2.
* There are 2 rectangles of side 3x1.
* There is 1 rectangle of side 3x2.
* Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
* 
* 
* Constraints:
* 
* 1 <= m, n <= 150
* mat[i][j] is either 0 or 1.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    long long numSubmat(vector<vector<int>>& mat) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        vector<int> heights(n, 0);
        long long ans = 0;

        for (int i = 0; i < m; ++i) {
            // 1) 현재 행을 바닥으로 하는 히스토그램 높이 갱신
            for (int j = 0; j < n; ++j) {
                heights[j] = (mat[i][j] == 1) ? heights[j] + 1 : 0;
            }

            // 2) 단조 증가 스택으로 현재 행에서의 직사각형 수 계산
            // 스택 원소: (height, widthCount)
            stack<pair<int,int>> st;
            long long rowSum = 0;

            for (int j = 0; j < n; ++j) {
                int h = heights[j];
                int width = 1;

                // 높이가 현재보다 크거나 같은 구간을 병합
                while (!st.empty() && st.top().first >= h) {
                    auto [ph, pw] = st.top(); st.pop();
                    rowSum -= 1LL * ph * pw;
                    width += pw;
                }

                if (h > 0) {
                    st.emplace(h, width);
                    rowSum += 1LL * h * width;
                } else {
                    // h == 0 이면 구간이 끊기므로 스택을 비우는 효과
                    // (위 while에서 이미 큰 높이들은 빠졌고,
                    //  0은 넣어도 기여가 없으니 생략)
                }

                ans += rowSum;
            }
        }
        return ans;
    }
};

int main() {
	Solution sol;
	
	mat = [[1,0,1],[1,1,0],[1,1,0]];
	ans = 13;

	mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]];
	ans = 24;

    return 0;
}
