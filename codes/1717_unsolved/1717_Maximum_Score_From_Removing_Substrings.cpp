/**
 * 1717. Maximum Score From Removing Substrings
 * You are given a string s and two integers x and y. You can perform two types of operations any number of times.
 * 
 * Remove substring "ab" and gain x points.
 * For example, when removing "ab" from "cabxbae" it becomes "cxbae".
 * Remove substring "ba" and gain y points.
 * For example, when removing "ba" from "cabxbae" it becomes "cabxe".
 * Return the maximum points you can gain after applying the above operations on s.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s = "cdbcbbaaabab", x = 4, y = 5
 * Output: 19
 * Explanation:
 * - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
 * - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
 * - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
 * - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
 * Total score = 5 + 4 + 5 + 5 = 19.
 * Example 2:
 * 
 * Input: s = "aabbaaxybbaabb", x = 5, y = 4
 * Output: 20
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 10^5
 * 1 <= x, y <= 10^4
 * s consists of lowercase English letters.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
private:
	int removePair(string &s, const string &pattern, int score) {
		string temp;
		int res = 0;
		for (char c : s) {
			if (!temp.empty() && temp.back() == pattern[0] && c == pattern[1]) {
				temp.pop_back();
				res += score;
			} else {
				temp.push_back(c);
			}
		}
		s = temp;
		return res;
	}
public:
	int maximumGain(string s, int x, int y) {
		string first, second;
		int firstScore, secondScore;

		if (x >= y) {
			first = "ab"; firstScore = x;
			second = "ba"; secondScore = y;
		} else {
			first = "ba"; firstScore = y;
			second = "ab"; secondScore = x;
		}

		int total = 0;
		total += removePair(s, first, firstScore);
		total += removePair(s, second, secondScore);
		return total;
	}
};

int main() {
	Solution sol;
	string s;
	int x,y;
	int ans,res;

	s = "cdbcbbaaabab";
	x = 4;
	y = 5;
	ans = 19;
	res = sol.maximumGain(s,x,y);
	println("ans : {}, res :{}",ans,res);

	s = "aabbaaxybbaabb";
	x = 5;
	y = 4;
	ans = 20;
	res = sol.maximumGain(s,x,y);
	println("ans : {}, res :{}",ans,res);

	return 0;
}
