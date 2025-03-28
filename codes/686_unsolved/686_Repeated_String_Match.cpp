/*
   686. Repeated String Match
   Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

   Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".



   Example 1:

   Input: a = "abcd", b = "cdabcdab"
   Output: 3
   Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
   Example 2:

   Input: a = "a", b = "aa"
   Output: 2


   Constraints:

   1 <= a.length, b.length <= 104
   a and b consist of lowercase English letters.

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <print>

using namespace std;
class Solution {
public:
	int repeatedStringMatch(string a, string b) {

		return 0;
	}
};

int main() {
	Solution sol;	
	string a,b;
	int ans, res;

	a = "abcd";
	b = "cdabcdab";
	ans = 3;
	res = sol.repeatedStringMatch(a,b);
	println("a : {}  b : {} \n ans : {} res : {}",a,b,ans,res);
	assert(ans == res);

	a = "a";
	b = "aa";
	ans = 2;
	res = sol.repeatedStringMatch(a,b);
	println("a : {}  b : {} \n ans : {} res : {}",a,b,ans,res);
	assert(ans == res);

	cout << "Accepted!" <<endl;
	return 0;
}
