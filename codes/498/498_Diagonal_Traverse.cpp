/**
 * 498. Diagonal Traverse
 * Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 * 
 *  
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,4,7,5,3,6,8,9]
 * Example 2:
 * 
 * Input: mat = [[1,2],[3,4]]
 * Output: [1,2,3,4]
 *  
 * 
 * Constraints:
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * -105 <= mat[i][j] <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

#if 0
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        const int n = static_cast<int>(mat.size());
        const int m = static_cast<int>(mat[0].size());
        vector<int> ans;
        ans.reserve(n * m);
        int r = 0, c = 0;
        bool up = true; // false = lower / true = upper
        for (int k = 0; k < n * m; ++k) {
            ans.push_back(mat[r][c]);
            if (up) {
                if (c == m - 1) {
                    ++r;
                    up = false;
                } else if (r == 0) {
                    ++c;
                    up = false;
                } else {
                    --r; ++c;
                }
            } else {
                if (r == n - 1) {
                    ++c;
                    up = true;
                } else if (c == 0) {
                    ++r;
                    up = true;
                } else {
                    ++r; --c;
                }
            }
        }

        return ans;
    }
};
#else

class Solution {
private:
static inline long long prefixSum(int s, int n, int m) {
    long long a = min(n, m);
    long long b = max(n, m);
    long long D = n + m - 1; // #diagonals
    if (s <= a) {
        return 1LL * s * (s + 1) / 2;
    } else if (s <= b) {
        return 1LL * a * (a + 1) / 2 + 1LL * (s - a) * a;
    } else {
        long long k = s - b;
        return 1LL * a * (a + 1) / 2 + 1LL * (b - a) * a
             + k * (2LL * D - b - s + 1) / 2;
    }
}

static inline long long indexOf(int i, int j, int n, int m) {
    int s = i + j;
    int i_start = max(0, s - (m - 1));
    int i_end   = min(n - 1, s);
    long long off = (s % 2 == 0) ? (i_end - i) : (i - i_start);
    return prefixSum(s, n, m) + off;
}
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        const int n = (int)mat.size();
        const int m = (int)mat[0].size();

        vector<int> ans(n * m);
        // 각 (i,j)를 “결과에서의 위치”에 바로 배치
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long idx = indexOf(i, j, n, m);
                ans[(size_t)idx] = mat[i][j];
            }
        }
        return ans;
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> mat;
	vector<int> ans, res;

	mat = {{1,2,3},{4,5,6},{7,8,9}};
	ans = {1,2,4,7,5,3,6,8,9};
	res = sol.findDiagonalOrder(mat);
	println("ans :{}\nres :{}",ans,res);

	mat = {{1,2},{3,4}};
	ans = {1,2,3,4};
	res = sol.findDiagonalOrder(mat);
	println("ans :{}\nres :{}",ans,res);

	return 0;
}
