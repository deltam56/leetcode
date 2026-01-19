/**
 * 2975. Maximum Square Area by Removing Fences From a Field
 * There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.
 * 
 * Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).
 * 
 * Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.
 * 
 * Since the answer may be large, return it modulo 109 + 7.
 * 
 * Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
 * Output: 4
 * Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
 * Example 2:
 * 
 * 
 * 
 * Input: m = 6, n = 7, hFences = [2], vFences = [4]
 * Output: -1
 * Explanation: It can be proved that there is no way to create a square field by removing fences.
 * 
 * 
 * Constraints:
 * 
 * 3 <= m, n <= 109
 * 1 <= hFences.length, vFences.length <= 600
 * 1 < hFences[i] < m
 * 1 < vFences[i] < n
 * hFences and vFences are unique.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <set>
const int MOD = 1e9+7;
using namespace std;

class Solution {
public:
	int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
		if(m==n) return static_cast<int>(1LL*m*n%MOD);
		int maxh = 0;
		int maxv = 0;

		vector<int> h = {1, m};
		vector<int> v = {1, n};
		for (int x : hFences) h.push_back(x);
		for (int y : vFences) v.push_back(y);
		sort(h.begin(), h.end());
		sort(v.begin(), v.end());

		set<int> hLengths;
		for (int i = 0; i < h.size(); i++) {
			for (int j = i + 1; j < h.size(); j++) {
				hLengths.insert(h[j] - h[i]);
			}
		}
		set<int> vLengths;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				hLengths.insert(v[j] - v[i]);
			}
		}




		return -1;
	}
};

int main() {
	Solution sol;
	int m,n;
	vector<int> hFences,vFences;
	int ans,res;

	m = 4, n = 3, hFences = {2,3}, vFences = {2};
	ans = 4;
	res = sol.maximizeSquareArea(m,n,hFences,vFences);
	println("ans : {}, res : {}",ans,res);

	m = 6, n = 7, hFences = {2}, vFences = {4};
	ans = -1;
	res = sol.maximizeSquareArea(m,n,hFences,vFences);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
