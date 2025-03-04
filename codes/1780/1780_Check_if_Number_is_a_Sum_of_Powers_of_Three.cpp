/**
* 1780. Check if Number is a Sum of Powers of Three
*
*
* Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
* 
* An integer y is a power of three if there exists an integer x such that y == 3x.
* 
* 
* 
* Example 1:
* 
* input: n = 12
* output: true
* explanation: 12 = 3^1 + 3^2
* example 2:
* 
* input: n = 91
* output: true
* explanation: 91 = 3^0 + 3^2 + 3^4
* example 3:
* 
* input: n = 21
* output: false
* 
* 
* Constraints:
* 
* - 1 <= n <= 10^7
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    bool checkPowersOfThree(int n) {
		while(n>0 ){
			if(n % 3 == 2)
				return false;
			n = n/3;
		}
		return true;
    }
};


int main() {
	Solution sol;
	int n = 0;
	bool ans,res;

	n = 12;
	ans = true;
	res = sol.checkPowersOfThree(n);
	println("ans : {}  res : {}" ,ans,res);
	assert(ans==res);

	n = 91;
	ans = true;
 	res = sol.checkPowersOfThree(n);
	println("ans : {}  res : {}" ,ans,res);
	assert(ans==res);

	n = 21;
	ans = false;
 	res = sol.checkPowersOfThree(n);
	println("ans : {}  res : {}" ,ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
    return 0;
}
