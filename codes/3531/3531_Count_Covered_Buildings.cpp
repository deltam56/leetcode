/**
* 3531. Count Covered Buildings
* You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

A building is covered if there is at least one building in all four directions: left, right, above, and below.

Return the number of covered buildings.

 

Example 1:



Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]

Output: 1

Explanation:

Only building [2,2] is covered as it has at least one building:
above ([1,2])
below ([3,2])
left ([2,1])
right ([2,3])
Thus, the count of covered buildings is 1.
Example 2:



Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]

Output: 0

Explanation:

No building has at least one building in all four directions.
Example 3:



Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]

Output: 1

Explanation:

Only building [3,3] is covered as it has at least one building:
above ([1,3])
below ([5,3])
left ([3,2])
right ([3,5])
Thus, the count of covered buildings is 1.
 

Constraints:

2 <= n <= 10^5
1 <= buildings.length <= 10^5 
buildings[i] = [x, y]
1 <= x, y <= n
All coordinates of buildings are unique.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> rowMin, rowMax;
        unordered_map<int, int> colMin, colMax;

        for (const auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!rowMin.count(x)) {
                rowMin[x] = rowMax[x] = y;
            } else {
                rowMin[x] = min(rowMin[x], y);
                rowMax[x] = max(rowMax[x], y);
            }
            if (!colMin.count(y)) {
                colMin[y] = colMax[y] = x;
            } else {
                colMin[y] = min(colMin[y], x);
                colMax[y] = max(colMax[y], x);
            }
        }
        int cnt = 0;
        for (const auto& b : buildings) {
            int x = b[0], y = b[1];
            bool hasLeftRight  = (rowMin[x] < y && y < rowMax[x]);
            bool hasUpDown     = (colMin[y] < x && x < colMax[y]);
            if (hasLeftRight && hasUpDown) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
	Solution sol;
	int n;
	vector<vector<int>> buildings;
	int ans,res;

	n = 3, buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
	ans = 1;
	res = sol.countCoveredBuildings(n,buildings);
	println("ans : {}, res : {}",ans,res);

	n = 3, buildings = {{1,1},{1,2},{2,1},{2,2}};
	ans = 0;
	res = sol.countCoveredBuildings(n,buildings);
	println("ans : {}, res : {}",ans,res);

	n = 5, buildings = {{1,3},{3,2},{3,3},{3,5},{5,3}};
	ans = 1;
	res = sol.countCoveredBuildings(n,buildings);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
