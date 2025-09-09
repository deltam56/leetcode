/**
 * 1317. Convert Integer to the Sum of Two No-Zero Integers
 * No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.
 * 
 * Given an integer n, return a list of two integers [a, b] where:
 * 
 * a and b are No-Zero integers.
 * a + b = n
 * The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: n = 2
 * Output: [1,1]
 * Explanation: Let a = 1 and b = 1.
 * Both a and b are no-zero integers, and a + b = 2 = n.
 * Example 2:
 * 
 * Input: n = 11
 * Output: [2,9]
 * Explanation: Let a = 2 and b = 9.
 * Both a and b are no-zero integers, and a + b = 11 = n.
 * Note that there are other valid answers as [8, 3] that can be accepted.
 * 
 * 
 * Constraints:
 * 
 * 2 <= n <= 10^4
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> getNoZeroIntegers(int n) {
		vector<int> ret;
		for(int i = 0 ; i < n ; ++i){
			string num = to_string(i);
			string num2 = to_string(n-i);
			if((num.find('0')==string::npos)&&(num2.find('0')==string::npos)){
				ret.push_back(i);
				ret.push_back(n-i);
				break;
			}
		}
		return ret;
	}
};

int main() {
	Solution sol;
	int n;
	vector<int> ans,res;

	n = 2;
	ans = {1,1};
	res = sol.getNoZeroIntegers(n);
	println("ans: {}, res :{}",ans,res);

	n = 11;
	ans = {2,9};
	res = sol.getNoZeroIntegers(n);
	println("ans: {}, res :{}",ans,res);

	return 0;
}
