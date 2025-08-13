/**
* 326. Power of Three
* Given an integer n, return true if it is a power of three. Otherwise, return false.
* 
* An integer n is a power of three, if there exists an integer x such that n == 3x.
* 
* 
* 
* Example 1:
* 
* Input: n = 27
* Output: true
* Explanation: 27 = 33
* Example 2:
* 
* Input: n = 0
* Output: false
* Explanation: There is no x where 3x = 0.
* Example 3:
* 
* Input: n = -1
* Output: false
* Explanation: There is no x where 3x = (-1).
* 
* 
* Constraints:
* 
* -2^31 <= n <= 2^31 - 1
* 
* 
* Follow up: Could you solve it without loops/recursion?
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <cmath>
using namespace std; //편의성위해..

class Solution {
private:
    static constexpr double EPS = 1e-12;

    static double log_base3(double n) {
        return std::log(n) / std::log(3.0);
    }
    static bool isInteger(double x) {
        double r = std::round(x);
        return std::fabs(x - r) < EPS;
    }
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return isInteger(log_base3(n));
    }
};

int main() {
	Solution sol;
	int n;
	bool ans,res;

	n = 243;
	ans = true;
	res = sol.isPowerOfThree(n);
	println("ans : {}, res : {}",ans,res);

	n = 27;
	ans = true;
	res = sol.isPowerOfThree(n);
	println("ans : {}, res : {}",ans,res);

	n = 0;
	ans = false;
	res = sol.isPowerOfThree(n);
	println("ans : {}, res : {}",ans,res);

	n = -1;
	ans = false;
	res = sol.isPowerOfThree(n);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
