/*
1910. Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.



Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".


Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

void print(string ans, string res ){
	cout << "ans : " << ans;
	cout << "   res : " <<res <<endl;
	assert(ans == res);

}
class Solution {
public:
    string removeOccurrences(string s, string part) {
		int i = 0;
		int m = part.length();
		while(i < s.length() - (part.length()-1)){
			if (s.empty())
				return s;
            if (s.substr(i, part.length()) == part) {
                s.erase(i, part.length());
                i = max(0, i -m);
            } else {
                i++;
            }
		}
		return s;
    }
};

#if 0
class Solution {
public:
	string removeOccurrences(string s, string part) {
		const int m = part.length();
		string str(s);
		int j = 0;

		for (int i = 0; i < s.length(); ++i) {
			str[j++] = s[i];

			if (j >= m and str.substr(j - m, m) == part)
				j -= m;
		}

		return str.substr(0, j);
	}
};
#endif

int main() {
	Solution sol;
	string s, part;
	string ans;
	string res;

	s = "daabcbaabcbc";
	part = "abc";
	ans = "dab";
	res = sol.removeOccurrences(s,part);
	assert(res == ans);
	cout << res << endl;

	s = "axxxxyyyyb";
	part = "xy";
	ans = "ab";
	res = sol.removeOccurrences(s,part);
	assert(res == ans);
	cout << res << endl;

	s = "eemckxmckx";
	part = "emckx";
	ans = "";
	res = sol.removeOccurrences(s,part);
	print(ans, res);
	cout << res << endl;

	s ="ixcupqoixcupqokevnpokevnpoknqywmlhevgc";
	part = "ixcupqokevnpo";
	ans = "knqywmlhevgc";
	res = sol.removeOccurrences(s,part);
	print(ans, res);
	cout << res << endl;

//	s = "ccctltctlltlb";
//	part = "ctl";
	cout << "Accepted!" <<endl;

    return 0;
}
