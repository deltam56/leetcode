/**
* 166. Fraction to Recurring Decimal
* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
* 
* If the fractional part is repeating, enclose the repeating part in parentheses.
* 
* If multiple answers are possible, return any of them.
* 
* It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
* 
*  
* 
* Example 1:
* 
* Input: numerator = 1, denominator = 2
* Output: "0.5"
* Example 2:
* 
* Input: numerator = 2, denominator = 1
* Output: "2"
* Example 3:
* 
* Input: numerator = 4, denominator = 333
* Output: "0.(012)"
*  
* 
* Constraints:
* 
* -2^31 <= numerator, denominator <= 2^31 - 1
* denominator != 0
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
        bool neg = ((numerator < 0) ^ (denominator < 0));
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        long long integerPart = n / d;
        long long rem = n % d;

        string res;
        if (neg) res.push_back('-');
        res += to_string(integerPart);

        if (rem == 0) return res;

        res.push_back('.');

        unordered_map<long long, int> pos;
        while (rem != 0) {
            if (pos.count(rem)) {
                res.insert(pos[rem], "(");
                res.push_back(')');
                break;
            }
            pos[rem] = (int)res.size();

            rem *= 10;
            long long digit = rem / d;
            res.push_back(char('0' + digit));
            rem %= d;
        }
        return res;
    }
};

int main() {
	Solution sol;
	int numerator, denominator;
	string ans,res;

	numerator = 1, denominator = 2;
	ans = "0.5";
	res = sol.fractionToDecimal(numerator,denominator);
	println("ans: {}, res : {}",ans,res);

	numerator = 2, denominator = 1;
	ans = "2";
	res = sol.fractionToDecimal(numerator,denominator);
	println("ans: {}, res : {}",ans,res);

	numerator = 4, denominator = 333;
	ans = "0.(012)";
	res = sol.fractionToDecimal(numerator,denominator);
	println("ans: {}, res : {}",ans,res);

    return 0;
}
