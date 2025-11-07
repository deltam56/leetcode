/**
* 2528. Maximize the Minimum Powered City
* You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.
* 
* Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.
* 
* Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
* The power of a city is the total number of power stations it is being provided power from.
* 
* The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.
* 
* Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.
* 
* Note that you can build the k power stations in multiple cities.
* 
* 
* 
* Example 1:
* 
* Input: stations = [1,2,4,5,0], r = 1, k = 2
* Output: 5
* Explanation:
* One of the optimal ways is to install both the power stations at city 1.
* So stations will become [1,4,4,5,0].
* - City 0 is provided by 1 + 4 = 5 power stations.
* - City 1 is provided by 1 + 4 + 4 = 9 power stations.
* - City 2 is provided by 4 + 4 + 5 = 13 power stations.
* - City 3 is provided by 5 + 4 = 9 power stations.
* - City 4 is provided by 5 + 0 = 5 power stations.
* So the minimum power of a city is 5.
* Since it is not possible to obtain a larger power, we return 5.
* Example 2:
* 
* Input: stations = [4,4,4,4], r = 0, k = 3
* Output: 4
* Explanation:
* It can be proved that we cannot make the minimum power of a city greater than 4.
* 
* 
* Constraints:
* 
* n == stations.length
* 1 <= n <= 10^5
* 0 <= stations[i] <= 10^5
* 0 <= r <= n - 1
* 0 <= k <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

// class Solution {
// public:
//     long long maxPower(vector<int>& stations, int r, int k) {
// 		priority_queue<long long,vector<long long>, greater<long long>> powers;
// 		for(int i = 0; i < stations.size(); ++i){
// 			int le = i-r;
// 			int ri = i+r;
// 			long long power = 0;
// 			for(int j = le; j <= ri; ++j){
// 				if(j < 0 || j >stations.size())
// 					continue;
// 				power += stations[i];
// 			}
// 			powers.push(power);
// 		}
// 
// 		while(k > 0){
// 			long long tmp = powers.top();
// 			powers.pop();
// 			tmp++;
// 			powers.push(tmp);
// 			k --;
// 		}
// 		return powers.top();
//     }
// };
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        const int n = (int)stations.size();

        // 1) 초기 각 도시의 전력 (슬라이딩/프리픽스로 O(n))
        vector<long long> power(n);
        {
            vector<long long> pref(n + 1, 0);
            for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];
            for (int i = 0; i < n; ++i) {
                int L = max(0, i - r);
                int R = min(n - 1, i + r);
                power[i] = pref[R + 1] - pref[L];
            }
        }

        auto can = [&](long long X) -> bool {
            vector<long long> diff(n + 1, 0); // 추가 발전소 영향 차분
            long long used = 0;   // 쓴 추가 발전소 수
            long long active = 0; // 현재 위치에 누적된 추가 영향(+몇)
            for (int i = 0; i < n; ++i) {
                active += diff[i];
                long long cur = power[i] + active; // 현재 i 도시 전력
                if (cur < X) {
                    long long need = X - cur;      // 더 필요한 만큼
                    used += need;
                    if (used > k) return false;
                    int p = min(n - 1, i + r);     // 가장 오른쪽에 깔기
                    active += need;                // 지금 위치부터 영향 반영
                    int endIdx = p + r + 1;        // 영향이 끝나는 다음 칸
                    if (endIdx < n) diff[endIdx] -= need;
                }
            }
            return true;
        };

        long long lo = 0;
        long long hi = *max_element(power.begin(), power.end()) + k; // 넉넉한 상한
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (can(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
int main() {
	Solution sol;
	vector<int> stations;
	int r,k;
	int ans,res;

	stations = {1,2,4,5,0}, r = 1, k = 2;
	ans = 5;
	res = sol.maxPower(stations,r,k);
	println("ans : {}, res : {}",ans,res);

	stations = {4,4,4,4}, r = 0, k = 3;
	ans = 4;
	res = sol.maxPower(stations,r,k);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
