/**
* 1039. Minimum Score Triangulation of Polygon
* You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
* 
* Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
* 
* You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
* 
* Return the minimum possible score that you can achieve with some triangulation of the polygon.
* 
* 
* 
* Example 1:
* 
* 
* 
* Input: values = [1,2,3]
* 
* Output: 6
* 
* Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
* 
* Example 2:
* 
* 
* 
* Input: values = [3,7,4,5]
* 
* Output: 144
* 
* Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
* The minimum score is 144.
* 
* Example 3:
* 
* 
* 
* Input: values = [1,3,1,4,1,5]
* 
* Output: 13
* 
* Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
* 
* 
* 
* Constraints:
* 
* n == values.length
* 3 <= n <= 50
* 1 <= values[i] <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = (int)values.size();
        if (n < 3) return 0;

        // dp[i][j] : 정점 i..j 로 이루어진 부분 다각형의 최소 점수
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // 구간 길이(len) = j - i
        for (int len = 2; len < n; ++len) {           // len < 2면 삼각형 불가
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                if (j - i < 2) {                      // 안전 체크(삼각형 X)
                    dp[i][j] = 0;
                    continue;
                }
                long long best = LLONG_MAX;
                for (int k = i + 1; k < j; ++k) {
                    long long cost = dp[i][k] + dp[k][j]
                                   + 1LL * values[i] * values[k] * values[j];
                    best = min(best, cost);
                }
                dp[i][j] = best;
            }
        }
        return (int)dp[0][n - 1];
    }
};

int main() {
	Solution sol;
	vector<int> values;
	int ans,res;

	values = {1,2,3};
	ans = 6;
	res = sol.minScoreTriangulation(values);
	println("ans : {}, res : {}",ans,res);

	values = {3,7,4,5};
	ans = 144;
	res = sol.minScoreTriangulation(values);
	println("ans : {}, res : {}",ans,res);

	values = {1,3,1,4,1,5};
	ans = 13;
	res = sol.minScoreTriangulation(values);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
