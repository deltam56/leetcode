/**
 * 3027. Find the Number of Ways to Place People II
 *
 * * You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
 * 
 * We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)
 * 
 * You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.
 * 
 * Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.
 * 
 * Note that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners (1, 1), (1, 3), (3, 1), and (3, 3), because:
 * 
 * With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
 * With Alice at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the fence.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 0
 * Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0. 
 * Example 2:
 * 
 * 
 * Input: points = [[6,2],[4,4],[2,6]]
 * Output: 2
 * Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
 * - Place Alice at (4, 4) and Bob at (6, 2).
 * - Place Alice at (2, 6) and Bob at (4, 4).
 * You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
 * Example 3:
 * 
 * 
 * Input: points = [[3,1],[1,3],[1,1]]
 * Output: 2
 * Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
 * - Place Alice at (1, 1) and Bob at (3, 1).
 * - Place Alice at (1, 3) and Bob at (1, 1).
 * You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
 * Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
 *  
 * 
 * Constraints:
 * 
 * 2 <= n <= 1000
 * points[i].length == 2
 * -10^9 <= points[i][0], points[i][1] <= 10^9
 * All points[i] are distinct.
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
private:
struct Fenwick {
		int n;
		vector<int> bit;
		Fenwick(int n) : n(n), bit(n + 1, 0) {}
		void add(int idx, int val) {
			for (; idx <= n; idx += idx & -idx) bit[idx] += val;
		}
		int sumPrefix(int idx) const {
			int s = 0;
			for (; idx > 0; idx -= idx & -idx) s += bit[idx];
			return s;
		}
		int sumRange(int l, int r) const { // inclusive
			if (r < l) return 0;
			return sumPrefix(r) - sumPrefix(l - 1);
		}
	};

public:
	long long numberOfPairs(vector<vector<int>>& points) {
		const int n = (int)points.size();
		if (n < 2) return 0;

		// x 오름차순, x 같으면 y 내림차순(동일 x에서 위->아래 순으로 정렬)
		sort(points.begin(), points.end(),
			 [](const auto& a, const auto& b){
				 if (a[0] != b[0]) return a[0] < b[0];
				 return a[1] > b[1];
			 });

		// y 좌표 압축 (±1e9 대응)
		vector<long long> ys; ys.reserve(n);
		for (auto &p : points) ys.push_back(p[1]);
		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		auto Y = [&](long long y) {
			return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1; // 1-indexed
		};

		long long ans = 0;

		// i를 고정하고 j를 오른쪽으로 확장하는 스윕
		// fw에는 항상 "i와 j 사이의" 점들만 들어있게 유지
		for (int i = 0; i < n; ++i) {
			Fenwick fw((int)ys.size());

			for (int j = i + 1; j < n; ++j) {
				// Alice = i(좌상), Bob = j(우하) 조건: xA ≤ xB && yA ≥ yB
				if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
					int yl = (int)min(points[i][1], points[j][1]); // yB
					int yr = (int)max(points[i][1], points[j][1]); // yA
					int L = Y(yl), R = Y(yr);

					// 경계 포함: [yl, yr] 구간에 중간 점이 하나라도 있으면 실패
					if (fw.sumRange(L, R) == 0) ++ans;
				}
				// 현재 j를 "다음" 쿼리들에서 중간 집합에 포함시키기 위해 추가
				fw.add(Y(points[j][1]), 1);
			}
		}

		return ans;
	}
};
#else
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b){
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] > b[1];
             });

        const int n = (int)points.size();
        for (int i = 0; i < n; ++i) {
            int maxClipped = INT_MIN;

            for (int j = i+1; j < n; ++j) {
                if (points[j][1] <= points[i][1]) {
                    if (maxClipped < points[j][1]) {
                        ++count;
                    }
                    maxClipped = max(maxClipped, points[j][1]);
                }
            }
        }
        return count;
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> points;
	int ans,res;

	points = {{1,1},{2,2},{3,3}};
	ans = 0;
	res = sol.numberOfPairs(points);
	println("ans : {} ,res : {}",ans,res);


	points = {{6,2},{4,4},{2,6}};
	ans = 2;
	res = sol.numberOfPairs(points);
	println("ans : {} ,res : {}",ans,res);

	points = {{3,1},{1,3},{1,1}};
	ans = 2;
	res = sol.numberOfPairs(points);
	println("ans : {} ,res : {}",ans,res);

	return 0;
}
