/**
* 474. Ones and Zeroes
* You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.



Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.


Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
#if 0
    int findMaxForm(vector<string>& strs, int m, int n) {
		// str -> 2진수로 각 문자열 0, 1 갯수 파악해놓음
		// sack 문제로 풂

		// vector< { num 0 , num 1 }>
		vector<pair<long long,long long>> binnums;

		for(string s: strs){
			long long ones = __builtin_popcountll(stoi(s, nullptr, 2));
			binnums.push_back({s.size()-ones,ones});
		}
		

    }
#endif
	int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j] : 0을 i개, 1을 j개까지 사용 가능할 때 선택 가능한 문자열 최대 개수
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') ++zeros;
                else ++ones;
            }

            // 0-1 배낭: 역순으로 순회해야 같은 문자열을 중복 사용하지 않음
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
	Solution sol;
	vector<string> strs;
	int m,n;
	int ans,res;

	strs = {"10","0001","111001","1","0"}, m = 5, n = 3;
	ans = 4;
	res = sol.findMaxForm(strs,m,n);
	println("ans : {}, res : {}",ans,res);

	strs = {"10","0","1"}, m = 1, n = 1;
	ans = 2;
	res = sol.findMaxForm(strs,m,n);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
