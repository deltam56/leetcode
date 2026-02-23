/**
 * 3713. Longest Balanced Substring I
 * You are given a string s consisting of lowercase English letters.
 * 
 * A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
 * 
 * Return the length of the longest balanced substring of s.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: s = "abbac"
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
 * 
 * Example 2:
 * 
 * Input: s = "zzabccy"
 * 
 * Output: 4
 * 
 * Explanation:
 * 
 * The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​
 * 
 * Example 3:
 * 
 * Input: s = "aba"
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * One of the longest balanced substrings is "ab" 
 * because both distinct characters 'a' and 'b' each appear exactly 1 time.
 * Another longest balanced substring is "ba".
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//class Solution {
//	bool isBalanced(string sub){
//		unordered_map<char,int> freq;
//		for(char c:sub){
//			freq[c]++;
//		}
//		int val = freq.begin()->second;
//		return all_of(freq.begin(), freq.end(), [&](auto& p){ return p.second == val; });
//	}
//public:
//    int longestBalanced(string s) {
//		//length 를 m 으로 놓고, bs..?
//		int max_len = s.length();
//		int min_len = 1;
//		int mid = s.length()/2;
//
//		//bs part
//		//for{
//		//  if balanced -> mid = mid+max_len/2
//		//  else -> mid = mid+min_len/2
//		//  mid == max_len or mid == min_len -> return mid
//		//}
//		//
//    }
//};

class Solution {
public:
	int longestBalanced(string s) {
		int n = s.length();
		int ans = 1; // 길이 1은 항상 balanced
		for (int i = 0; i < n; i++) {
			unordered_map<char,int> freq;
			for (int j = i; j < n; j++) {
				freq[s[j]]++;
				int val = freq.begin()->second;
				if (all_of(freq.begin(), freq.end(),
						   [&](auto& p){ return p.second == val; }))
					ans = max(ans, j - i + 1);
			}
		}
		return ans;
	}
};
int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "abbac";
	ans = 4;
	res = sol.longestBalanced(s);
	println("ans : {}, res :{}",ans,res);

	s = "zzabccy";
	ans = 4;
	res = sol.longestBalanced(s);
	println("ans : {}, res :{}",ans,res);

	s = "aba";
	ans = 2;
	res = sol.longestBalanced(s);
	println("ans : {}, res :{}",ans,res);

	return 0;
}
