/**
* 
* 342. Power of Four
* Given an integer n, return true if it is a power of four. Otherwise, return false.
* 
* An integer n is a power of four, if there exists an integer x such that n == 4x.
* 
*  
* 
* Example 1:
* 
* Input: n = 16
* Output: true
* Example 2:
* 
* Input: n = 5
* Output: false
* Example 3:
* 
* Input: n = 1
* Output: true
*  
* 
* Constraints:
* 
* -2^31 <= n <= 2^31 - 1
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
    bool isPowerOfFour(int n) {
		if(n <= 0)
			return false;
		while(n >1){
			if(n%4 != 0){
				return false;
			}
			n = n/4;
		}
		return true;

    }
};
int main() {
	Solution sol;
	int n;
	bool ans,res;

	n = 16;
	ans = true;
	res = sol.isPowerOfFour(n);
	println("ans : {} , res :{}",ans,res);


	n = 5;
	ans = false;
	res = sol.isPowerOfFour(n);
	println("ans : {} , res :{}",ans,res);

	n = 1;
	ans = true;
	res = sol.isPowerOfFour(n);
	println("ans : {} , res :{}",ans,res);

    return 0;
}
