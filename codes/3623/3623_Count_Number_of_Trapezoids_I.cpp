/**
 * 3623. Count Number of Trapezoids I
 * You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
 * 
 * A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.
 * 
 * Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.
 * 
 * Since the answer may be very large, return it modulo 109 + 7.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * 
 * 
 * There are three distinct ways to pick four points that form a horizontal trapezoid:
 * 
 * Using points [1,0], [2,0], [3,2], and [2,2].
 * Using points [2,0], [3,0], [3,2], and [2,2].
 * Using points [1,0], [3,0], [3,2], and [2,2].
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
 * There is only one horizontal trapezoid that can be formed.
 * 
 *  
 * 
 * Constraints:
 * 
 * 4 <= points.length <= 10^5
 * –10^8 <= xi, yi <= 10^8
 * All points are pairwise distinct.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>


using namespace std;
#if 1
class Solution {
private:
    static const int MOD = 1e9 + 7;

public:
    int countTrapezoids(vector<vector<int>>& points) {
        // y별 개수 카운트
        unordered_map<int, long long> y_cnts;
        y_cnts.reserve(points.size() * 2);
        for (auto &p : points) {
            y_cnts[p[1]]++;
        }

        long long S = 0;   // sum of a_i
        long long SQ = 0;  // sum of a_i^2
        int validLines = 0;

        for (auto &[y, cnt] : y_cnts) {
            if (cnt >= 2) {
                validLines++;
                // a_i = C(cnt, 2) = cnt * (cnt - 1) / 2
                long long ai = cnt * (cnt - 1) / 2;
                ai %= MOD;               // 미리 mod로 줄여두기

                S  = (S  + ai) % MOD;
                SQ = (SQ + ai * ai % MOD) % MOD;
            }
        }

        // 수평선 2개 미만이면 사다리꼴 못 만듦
        if (validLines < 2) return 0;

        // (S^2 - SQ) / 2 mod
        long long ans = (S * S) % MOD;
        ans = (ans - SQ + MOD) % MOD;   // 음수 방지

        // MOD는 소수니까 2의 역원은 (MOD + 1) / 2
        long long inv2 = (MOD + 1) / 2;
        ans = ans * inv2 % MOD;

        return (int)ans;
    }
};

#else
class Solution {
private:
	const int MOD = 1e9+7;
	long long nCr(int n, int r) {
		if (r > n) return 0;
		if (r == 0 || r == n) return 1;
		if (r > n - r) r = n - r;

		long long res = 1;
		for (int i = 1; i <= r; i++) {
			res = res * (n - r + i) / i;
		}
		return res;
	}
public:
	int countTrapezoids(vector<vector<int>>& points) {
		// 쭉 순회하면서 hashmap 에 y 출몰 횟수 적어두고
		// 각 y 값 보면서, y[i] > 2 면, y[i]C2 값을 누적 곱 하되 modulo 하면 될듯

		unordered_map<int,int> y_cnts;
		int ret = 0;
		int escape_cnt=0;
		vector<int> a2;
		for(vector<int> ptn : points){
			y_cnts[ptn[1]]++;
		}

		for(const auto& [y,cnt]: y_cnts){
			if(cnt > 1){
				escape_cnt++;
				a2.push_back(nCr(cnt,2));
			}
		}

		for(int i = 0 ; i < a2.size(); ++i){
			for(int j = i+1; j < a2.size(); ++j){
				ret += (a2[i]*a2[j])%MOD;
			}
		}

		if(escape_cnt < 2)return 0;
		return ret;
	}
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> points;
	int ans,res;

	points = {{-73,-72},{-1,-56},{-92,30},{-57,-89},{-19,-89},{-35,30},{64,-72}};
	ans = 3;
	res = sol.countTrapezoids(points);
	println("ans : {}, res : {}",ans,res);


	points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
	ans = 3;
	res = sol.countTrapezoids(points);
	println("ans : {}, res : {}",ans,res);

	points = {{0,0},{1,0},{0,1},{2,1}};
	ans = 1;
	res = sol.countTrapezoids(points);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
