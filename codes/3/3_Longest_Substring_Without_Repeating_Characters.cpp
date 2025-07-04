/**
 * 3. Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest substring without duplicate characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * 
 * Constraints:
 * 
 * 0 <= s.length <= 5 * 104
 * s consists of English letters, digits, symbols and spaces.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std; //편의성위해..

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> charIndex;
		int maxLength = 0;
		int start = 0;

		for (int end = 0; end < s.length(); ++end) {
			char c = s[end];
			if (charIndex.find(c) != charIndex.end() && charIndex[c] >= start) {
				start = charIndex[c] + 1;
			}
			charIndex[c] = end;
			maxLength = max(maxLength, end - start + 1);
		}
		return maxLength;
	}
};
int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "abcabcbb";
	ans = 3;
	res = sol.lengthOfLongestSubstring(s);
	println("ans :{} res :{}",ans,res);

	s = "bbbbb";
	ans = 1;
	res = sol.lengthOfLongestSubstring(s);
	println("ans :{} res :{}",ans,res);

	s = "pwwkew";
	ans = 3;
	res = sol.lengthOfLongestSubstring(s);
	println("ans :{} res :{}",ans,res);
	return 0;
}
