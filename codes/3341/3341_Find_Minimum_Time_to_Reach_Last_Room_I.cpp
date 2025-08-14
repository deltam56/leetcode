/**
 * 3341. Find Minimum Time to Reach Last Room I
 * There is a dungeon with n x m rooms arranged as a grid.
 * 
 * You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
 * 
 * Return the minimum time to reach the room (n - 1, m - 1).
 * 
 * Two rooms are adjacent if they share a common wall, either horizontally or vertically.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: moveTime = [[0,4],[4,4]]
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * The minimum time required is 6 seconds.
 * 
 * - At time t == 4, move from room (0, 0) to room (1, 0) in one second.
 * - At time t == 5, move from room (1, 0) to room (1, 1) in one second.
 * Example 2:
 * 
 * Input: moveTime = [[0,0,0],[0,0,0]]
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The minimum time required is 3 seconds.
 * 
 * - At time t == 0, move from room (0, 0) to room (1, 0) in one second.
 * - At time t == 1, move from room (1, 0) to room (1, 1) in one second.
 * - At time t == 2, move from room (1, 1) to room (1, 2) in one second.
 * Example 3:
 * 
 * Input: moveTime = [[0,1],[1,2]]
 * 
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 2 <= n == moveTime.length <= 50
 * 2 <= m == moveTime[i].length <= 50
 * 0 <= moveTime[i][j] <= 10^9
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>
using namespace std;
#if 0
class Solution {
public:
	int minTimeToReach(vector<vector<int>>& moveTime) {
		int n = moveTime[0].size();
		int m = moveTime.size();
		int time=0;
		for(int x=0,y=0; x<n-1 && y<m-1 ;++time){
			if(moveTime[x+1][y] - time <= 0){
				x = x+1;
			}
			if(moveTime[x][y+1] - time <= 0){
				y = y+1;
			}
		}
		return time;
	}
};
#else
class Solution {
public:
	int minTimeToReach(vector<vector<int>>& moveTime) {
		int n = moveTime.size(), m = moveTime[0].size();
		vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));

		// 🔧 시작 시간은 moveTime[0][0]
		int startTime = moveTime[0][0];
		minTime[0][0] = startTime;

		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
		pq.emplace(startTime, 0, 0);  // time, x, y

		int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
		while (!pq.empty()) {
			auto [time, x, y] = pq.top(); pq.pop();

			if (time > minTime[x][y]) continue;
			if (x == n - 1 && y == m - 1) return time;

			for (auto& d : dirs) {
				int nx = x + d[0];
				int ny = y + d[1];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					int nextTime = max(time + 1, moveTime[nx][ny]);
					if (minTime[nx][ny] > nextTime) {
						minTime[nx][ny] = nextTime;
						pq.emplace(nextTime, nx, ny);
					}
				}
			}
		}
		return -1;
	}
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> moveTime;
	int ans, res;

	moveTime = {{0,4},{4,4}};
	ans = 6;
	res = sol.minTimeToReach(moveTime);
	println("ans : {} , res : {}",ans, res);

	moveTime = {{0,0,0},{0,0,0}};
	ans = 3;
	res = sol.minTimeToReach(moveTime);
	println("ans : {} , res : {}",ans, res);

	moveTime = {{0,1},{1,2}};
	ans = 3;
	res = sol.minTimeToReach(moveTime);
	println("ans : {} , res : {}",ans, res);

	return 0;
}
