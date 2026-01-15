/**
* 3454. Separate Squares II
* You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
* 
* Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
* 
* Answers within 10-5 of the actual answer will be accepted.
* 
* Note: Squares may overlap. Overlapping areas should be counted only once in this version.
* 
* 
* 
* Example 1:
* 
* Input: squares = [[0,0,1],[2,2,1]]
* 
* Output: 1.00000
* 
* Explanation:
* 
* 
* 
* Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
* 
* Example 2:
* 
* Input: squares = [[0,0,2],[1,1,1]]
* 
* Output: 1.00000
* 
* Explanation:
* 
* 
* 
* Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
* 
* 
* 
* Constraints:
* 
* 1 <= squares.length <= 5 * 10^4
* squares[i] = [xi, yi, li]
* squares[i].length == 3
* 0 <= xi, yi <= 10^9
* 1 <= li <= 10^9
* The total area of all the squares will not exceed 10^15.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
		// 겹치는 부분을 알기위해 line sweep 을 쓰면될거같음
		// 겹치는 부분 고려해서 면적 구하는것으로 바꾸면 될듯
		// y+l 기준 sort
		// vector<int> (0~10^9) 를 만들어둠
		// y ~ y+1 범위 로 표시 해둠
		// mid 값은 0 ~ 10^9 로 시작
		// mid 아래 면적 계산을 하되, vector y ~ y+1 사이의 값이 더해진값 만큼 뺌 (0~5 index 가 1 1 2 2 2 라면 25 - 9 , 1 1 2 2 3 이라면 25 - 9 - 1 )
		// mid 탐색

		// y+l 기준 sort
		// max / min / mid 기준 -> y+l
		// 넓이 두개 두고, 같은지 작은지, 큰지 판단하면서 mid 옮기기(살짝 오차 수용)
		// y ~ y+l 구간에 mid 겹치면 -> 윗넓이 += 넓이 * (mid-y) ,아랫넓이+= 넓이 - 넓이*(mid-y)
		// 윗넓이 == 아랫넓이 return mid
		// 넓이 두개 갈 필요없음 아랫넒이 == 전체/2 면 해결
        double lo = INT_MAX, hi = INT_MIN;
        double totalArea = 0;

        for (auto& sq : squares) {
            double y = sq[1], l = sq[2];
            lo = min(lo, y);
            hi = max(hi, y + l);
            totalArea += (double)l * l;
        }

        double half = totalArea / 2.0;

        for (int iter = 0; iter < 100; iter++) {
            double mid = (lo + hi) / 2.0;
            double belowArea = 0;

            // mid 아래 면적 계산
            for (auto& sq : squares) {
                double x = sq[0], y = sq[1], l = sq[2];

                if (mid <= y) {
                    belowArea += 0;
                } else if (mid >= y + l) {
                    belowArea += l * l;
                } else {
                    // mid가 정사각형을 가로지름
                    belowArea += (mid - y) * l;
                }
            }

            if (belowArea < half) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};

int main() {
	Solution sol;
	vector<vector<int>> squares;
	double ans,res;

	squares = {{0,0,1},{2,2,1}};
	ans = 1.00000;
	res = sol.separateSquares(squares);
	println("ans : {}, res : {}",ans,res);

	squares = {{0,0,2},{1,1,1}};
	ans = 1.00000;
	res = sol.separateSquares(squares);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
