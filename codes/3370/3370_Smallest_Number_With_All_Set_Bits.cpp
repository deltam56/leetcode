/**
 * 3370. Smallest Number With All Set Bits
 * You are given a positive number n.
 * 
 * Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: n = 5
 * 
 * Output: 7
 * 
 * Explanation:
 * 
 * The binary representation of 7 is "111".
 * 
 * Example 2:
 * 
 * Input: n = 10
 * 
 * Output: 15
 * 
 * Explanation:
 * 
 * The binary representation of 15 is "1111".
 * 
 * Example 3:
 * 
 * Input: n = 3
 * 
 * Output: 3
 * 
 * Explanation:
 * 
 * The binary representation of 3 is "11".
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= n <= 1000
 * 
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;
class Solution {
public:
    int smallestNumber(int n) {
		vector<int> bins = {1,2,4,8,16,32,64,128,256,512,1024};
		for(int bin:bins)
			if(n < bin)
				return bin-1;
		return 0;
    }
};

int main() {
	Solution sol;
	int n;
	int ans,res;

	n = 5;
	ans = 7;
	res = sol.smallestNumber(n);
	println("ans : {}, res : {}",ans,res);

	n = 10;
	ans = 15;
	res = sol.smallestNumber(n);
	println("ans : {}, res : {}",ans,res);

	n = 3;
	ans = 3;
	res = sol.smallestNumber(n);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
