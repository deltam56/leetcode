/**
* 2843. Count Symmetric Integers
* You are given two positive integers low and high.
* 
* An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
* 
* Return the number of symmetric integers in the range [low, high].
* 
*  
* 
* Example 1:
* 
* Input: low = 1, high = 100
* Output: 9
* Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
* Example 2:
* 
* Input: low = 1200, high = 1230
* Output: 4
* Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
*  
* 
* Constraints:
* 
* 1 <= low <= high <= 10^4
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
		int count = 0;
		for(int i = low; i <= high ; i++){
			int f_half=0, s_half=0;
			string curnum = to_string(i);
			auto div_num = div(curnum.length(),2);
			if(div_num.rem)
				continue;
			for(int j = 0; j < div_num.quot ; j++){
				f_half += curnum[j] - '0';
				s_half += curnum[j + div_num.quot] - '0';
			}
			if(f_half == s_half)
				count++;
		}
		return count;
    }
};

int main() {
	Solution sol;
	int low,high;
	int ans = 0, res = 0;

	low = 1;
	high = 100;
	ans = 9;
    res = sol.countSymmetricIntegers(low,high);
	println("ans : {} , res : {}",ans, res);

	low = 1200;
	high = 1230;
	ans = 4;
	res = sol.countSymmetricIntegers(low,high);
	println("ans : {} , res : {}",ans, res);

    return 0;
}
