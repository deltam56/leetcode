/**
* 3625. Count Number of Trapezoids II
* You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
* 
* Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
* 
* A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.
* 
*  
* 
* Example 1:
* 
* Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
* 
* Output: 2
* 
* Explanation:
* 
* 
* 
* There are two distinct ways to pick four points that form a trapezoid:
* 
* The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
* The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
* Example 2:
* 
* Input: points = [[0,0],[1,0],[0,1],[2,1]]
* 
* Output: 1
* 
* Explanation:
* 
* 
* 
* There is only one trapezoid which can be formed.
* 
*  
* 
* Constraints:
* 
* 4 <= points.length <= 500
* –1000 <= xi, yi <= 1000
* All points are pairwise distinct.
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return (uint64_t(uint32_t(p.first)) << 32) ^ uint32_t(p.second);
    }
};

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        using pii = pair<int,int>;
        using ll  = long long;

        int n = points.size();

        auto getSlope = [&](const vector<int>& a, const vector<int>& b)->pii {
            int dx = b[0] - a[0];
            int dy = b[1] - a[1];
            int g = std::gcd(abs(dx), abs(dy));
            dx /= g; dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx; dy = -dy;
            }
            return {dy, dx};
        };

        unordered_map<pii, unordered_map<long long, vector<int>>, PairHash> lines;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                auto slope = getSlope(points[i], points[j]);
                long long dy = slope.first;
                long long dx = slope.second;
                long long c  = dy * points[i][0] - dx * points[i][1];

                auto &vec = lines[slope][c];
                vec.push_back(i);
                vec.push_back(j);
            }
        }

        ll total_trap = 0;

        for (auto &sl_entry : lines) {
            auto &lineMap = sl_entry.second;

            ll sumA = 0;
            ll sumA2 = 0;

            for (auto &ln_entry : lineMap) {
                auto &vec = ln_entry.second;
                sort(vec.begin(), vec.end());
                vec.erase(unique(vec.begin(), vec.end()), vec.end());

                ll k = (ll)vec.size();
                if (k >= 2) {
                    ll A = k * (k - 1) / 2; // C(k,2)
                    sumA  += A;
                    sumA2 += A * A;
                }
            }

            total_trap += (sumA * sumA - sumA2) / 2;
        }

        return (int)total_trap; // 일단은 이렇게
    }
};

int main() {
	Solution sol;
	vector<vector<int>> points;
	int ans,res;

	points = {{-3,2},{3,0},{2,3},{3,2},{2,-3}};
	ans = 2;
	res = sol.countTrapezoids(points);
	println("ans : {}, res : {}",ans, res);

	points = {{0,0},{1,0},{0,1},{2,1}};
	ans = 1;
	res = sol.countTrapezoids(points);
	println("ans : {}, res : {}",ans, res);

    return 0;
}
