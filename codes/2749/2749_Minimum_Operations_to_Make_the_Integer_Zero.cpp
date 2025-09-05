/**
* 2749. Minimum Operations to Make the Integer Zero
* You are given two integers num1 and num2.
* 
* In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.
* 
* Return the integer denoting the minimum number of operations needed to make num1 equal to 0.
* 
* If it is impossible to make num1 equal to 0, return -1.
* 
* 
* 
* Example 1:
* 
* Input: num1 = 3, num2 = -2
* Output: 3
* Explanation: We can make 3 equal to 0 with the following operations:
* - We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
* - We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
* - We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
* It can be proven, that 3 is the minimum number of operations that we need to perform.
* Example 2:
* 
* Input: num1 = 5, num2 = 7
* Output: -1
* Explanation: It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
* 
* 
* Constraints:
* 
* 1 <= num1 <= 10^9
* -10^9 <= num2 <= 10^9
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
    vector<long long> subnums;
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        int count = 0;
        subnums.resize(61);
        for (int i = 0; i <= 60; ++i) {
            subnums[i] = (1LL << i) + num2;
        }

        sort(begin(subnums), end(subnums), greater<long long>());

        while (num1 > 0) {
            bool used = false;
            for (long long v : subnums) {
                if (v <= num1) {
						if(v != 0){
						num1 -= v;
						++count;
						used = true;
						break;
					}
                }
            }
            if (!used) return -1;
        }

        return (num1 == 0 ? count : -1);
    }
};
#else
class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {
        for (int k = 1; k <= 60; ++k) {
            long long R = num1 - 1LL * k * num2;
            if (R < 0) continue;
            int ones = __builtin_popcountll(R);
            if (ones <= k && k <= R) {
                return k;
            }
        }
        return -1;
    }
};
#endif
int main() {
	Solution sol;
	int num1,num2;
	int ans,res;

	num1 = 5 ,num2 = -21;
	ans = 3;
	res = sol.makeTheIntegerZero(num1,num2);
	println("ans : {}, res : {}",ans, res);


	num1 = 3, num2 = -2;
	ans = 3;
	res = sol.makeTheIntegerZero(num1,num2);
	println("ans : {}, res : {}",ans, res);

	num1 = 5, num2 = 7;
	ans = -1;
	res = sol.makeTheIntegerZero(num1,num2);
	println("ans : {}, res : {}",ans, res);

    return 0;
}
