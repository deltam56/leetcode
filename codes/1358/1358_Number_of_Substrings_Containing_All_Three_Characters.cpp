/**
* 1358. Number of Substrings Containing All Three Characters
* Given a string s consisting only of characters a, b and c.
* 
* Return the number of substrings containing at least one occurrence of all these characters a, b and c.
* Example 1:
* 
* Input: s = "abcabc"
* Output: 10
* Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
* Example 2:
* 
* Input: s = "aaacb"
* Output: 3
* Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
* Example 3:
* 
* Input: s = "abc"
* Output: 1
*  
* 
* Constraints:
* 
* 3 <= s.length <= 5 x 10^4
* s only consists of a, b or c characters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <map>
#include <algorithm>

using namespace std; //편의성위해..

#if 0
class Solution {
public:
	int numberOfSubstrings(string s) {
		int res = 0;
		int left = 0;
		map<char, int> abc({{'a', 0}, {'b', 0}, {'c', 0}});
		int m = s.length();

		for (int right = 0; right < m; ++right) {
			abc[s[right]]++;

			while (abc['a'] > 0 && abc['b'] > 0 && abc['c'] > 0) {
				res += m - right;
				abc[s[left]]--;
				left++;
			}
		}
		return res;
	}
};
#else
class Solution {
public:
	int numberOfSubstrings(string s) {
		int res = 0;
		int left = 0;
		map<char, int> abc({{'a', 0}, {'b', 0}, {'c', 0}});
		int m = s.length();

		for (int right = 0; right < m; ++right) {
			abc[s[right]]++;

			while (abc['a'] > 0 && abc['b'] > 0 && abc['c'] > 0) {
				res += m - right;
				abc[s[left]]--;
				left++;
			}
		}
		return res;
	}
};
#endif

int main() {
	Solution sol;
	string s = "";
	int ans;
	int res;

	s = "abcabc";
	ans = 10;
	res = sol.numberOfSubstrings(s);
	println("ans : {} , res : {} ",ans, res);
	assert(ans == res);

	s = "aaacb";
	ans = 3;
	res = sol.numberOfSubstrings(s);
	println("ans : {} , res : {} ",ans, res);
	assert(ans == res);

	s = "abc";
	ans = 1;
	res = sol.numberOfSubstrings(s);
	println("ans : {} , res : {} ",ans, res);
	assert(ans == res);

	cout << "Accepted!" <<endl;
    return 0;
}
