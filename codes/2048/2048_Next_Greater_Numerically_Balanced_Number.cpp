/**
* 2048. Next Greater Numerically Balanced Number
* An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
* 
* Given an integer n, return the smallest numerically balanced number strictly greater than n.
* 
* 
* 
* Example 1:
* 
* Input: n = 1
* Output: 22
* Explanation:
* 22 is numerically balanced since:
* - The digit 2 occurs 2 times.
* It is also the smallest numerically balanced number strictly greater than 1.
* Example 2:
* 
* Input: n = 1000
* Output: 1333
* Explanation:
* 1333 is numerically balanced since:
* - The digit 1 occurs 1 time.
* - The digit 3 occurs 3 times.
* It is also the smallest numerically balanced number strictly greater than 1000.
* Note that 1022 cannot be the answer because 0 appeared more than 0 times.
* Example 3:
* 
* Input: n = 3000
* Output: 3133
* Explanation:
* 3133 is numerically balanced since:
* - The digit 1 occurs 1 time.
* - The digit 3 occurs 3 times.
* It is also the smallest numerically balanced number strictly greater than 3000.
* 
* 
* Constraints:
* 
* 0 <= n <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
class Solution {
private:
	static vector<int> buildBalanced() {
    set<int> S;

    for (int mask = 1; mask < (1 << 7); ++mask) {
        int L = 0;
        for (int d = 1; d <= 7; ++d) if (mask & (1 << (d - 1))) L += d;
        if (L > 7) continue;            // 7자리까지만 필요
        if (L == 0) continue;

        vector<int> digits;
        for (int d = 1; d <= 7; ++d) if (mask & (1 << (d - 1))) {
            digits.insert(digits.end(), d, d);
        }
        sort(digits.begin(), digits.end());

        do {
            long long x = 0;
            for (int v : digits) x = x * 10 + v;
            if (x <= INT_MAX) S.insert((int)x);
        } while (next_permutation(digits.begin(), digits.end()));
    }

    vector<int> v(S.begin(), S.end());
    return v;
}

vector<int> BAL = buildBalanced();
public:
    int nextBeautifulNumber(int n) {
		for(int i = 0; i < BAL.size(); ++i){
			if(n < BAL[i])
				return BAL[i];
		}

		return 0;
    }
};
int main() {
	Solution sol;
	int n;
	int ans,res;

	n = 1;
	ans = 22;
	res = sol.nextBeautifulNumber(n);
	println("ans : {}, res : {}",ans,res);

	n = 1000;
	ans = 1333;
	res = sol.nextBeautifulNumber(n);
	println("ans : {}, res : {}",ans,res);


	n = 3000;
	ans = 3133;
	res = sol.nextBeautifulNumber(n);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
